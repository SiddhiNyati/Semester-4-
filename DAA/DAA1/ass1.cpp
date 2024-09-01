#include <iostream>
#include <vector>
using namespace std;
struct Process {
    int id;
    int priority;
};
class PriorityQueue {
private:
    vector<Process> processes;
public:
    void insertProcess() {
        Process newProcess;
        cout << "Enter process ID: ";
        cin >> newProcess.id;
        cout << "Enter priority: "; 
        cin >> newProcess.priority;
        processes.push_back(newProcess);
        cout << "Process with ID " << newProcess.id << " inserted with priority " << newProcess.priority << endl;
    }  
    void deleteProcess() {
        if (processes.empty()) {
            cout << "Queue is empty. Nothing to delete." << endl;
            return;
        }        
        int maxPriorityIndex = 0;
        for (int i = 1; i < processes.size(); ++i) {
            if (processes[i].priority > processes[maxPriorityIndex].priority) {
                maxPriorityIndex = i;
            }
        }     
        Process deletedProcess = processes[maxPriorityIndex];
        processes.erase(processes.begin() + maxPriorityIndex);
        cout << "Process with ID " << deletedProcess.id << " and priority " << deletedProcess.priority << " deleted." << endl;
    }
    void displayProcesses() {
        if (processes.empty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Processes in the queue:" << endl;
            for (const Process &p : processes) {
                cout << "ID: " << p.id << ", Priority: " << p.priority << endl;
            }
        }
    }
};
int main() {
    PriorityQueue priorityQueue;
    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                priorityQueue.insertProcess();
                break;
            case 2:
                priorityQueue.deleteProcess();
                break;
            case 3:
                priorityQueue.displayProcesses();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }
    }
    return 0;
}

