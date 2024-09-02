#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct job{
    char name[2];
    int arrival_time;
    int execution_time;
};

void removeendline(char line[]){
    int len = strlen(line);
    if(line[len-1]=='\n'){
        line[len-1] = '\0';
    }
}

void sort(struct job jobs[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(jobs[j].arrival_time > jobs[j+1].arrival_time){
                struct job temp  = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+ 1] = temp;
            }
        }
    }
}

void fcfs(struct job jobs[],int n){
    int current_time = 0;
    printf("I\tN\tA\tE\n");
    int index = 0;
    for(int i=0;i<n;i++){
        int start_time = 0;
        if(current_time > jobs[i].arrival_time){
            start_time = current_time;
        }else{
            start_time = jobs[i].arrival_time;
        }
        int endtime = start_time + jobs[i].execution_time;
        if (current_time < jobs[i].arrival_time) {
            index = index +1;
            printf("%d\tIdle\t%d\t%d\n", index, current_time, jobs[i].arrival_time);
            current_time = jobs[i].arrival_time;
        }
        index = index + 1;
        printf("%d\t%s\t%d\t%d\n",index,jobs[i].name,start_time,endtime);
        current_time = endtime;
    }
}

int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    struct job jobs[n];
    FILE * file;
    file = fopen("jobs","r");
    if(file == NULL){
        printf("File did'nt open....\n");
        return 1;
    }
    int i = 0;
    char line[100];
    while(fgets(line,100,file)!=NULL){
        removeendline(line);
        if(i%3 == 0){
            strcpy(jobs[i/3].name,line);
        }else if(i%3 == 1){
            jobs[i/3].arrival_time = atoi(line);
        }else{
            jobs[i/3].execution_time = atoi(line);
        }
        i++;
    }
    sort(jobs,n);
    fcfs(jobs,n);
}

