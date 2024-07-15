#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <deque>
#include <array>

using namespace std;

void addtask(vector <string>& tasks){
    string task;
    cout << "Enter your task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added. " << endl;
}

void viewTasks(vector <string>& tasks){
    if(tasks.empty()){
        cout << "No tasks in the list. " << endl;
        return;
    }
    for(int i = 0; i < tasks.size(); i++){
        cout << i+1 << ". " << tasks[i] << endl;
    }
}

void markCompleted(vector <string>& tasks){
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    index -= 1;
    if(index >= 0 && index < tasks.size()){
        tasks[index].push_back(' ');
        tasks[index].push_back('[');
        tasks[index].push_back('#');
        tasks[index].push_back(']');
        cout << "Task completed. " << endl;
    }
    else cout << "Invalid task number. " << endl;
}

void removeTask(vector <string>& tasks){
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if(index > 0 && index <= tasks.size()){
        tasks.erase(tasks.begin() + index);
        cout << "Task deleted." << endl;
    }
    else{
        cout << "Invalid task number." << endl;
    }
}

int main(){

int choice;
vector <string> tasks;

while(true){

    cout << endl << "--- To-Do List Manager ---" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark task as completed" << endl;
    cout << "4. Remove the task" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1: // add task
        addtask(tasks);
        break;
    
    case 2: // view tasks
        viewTasks(tasks);
        break;

    case 3: // mark the task
        markCompleted(tasks);
        break;

    case 4: // remove the task
        removeTask(tasks);
        break;

    case 5: // quit
        cout << "Goodbye!" << endl;
        break;

    default:
        cout << "Invalid number. Please try again! " << endl;
        break;
    }
}

return 0;
}