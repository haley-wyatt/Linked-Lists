/*
Name: Wyatt Haley
Class: Data Structures
File name: driver.cpp
*/

#include <iostream>
#include <limits>

#include "linkedlist.h"

int getTaskPriority(int listLength);
int getMenuChoice();
void insertTask(LinkedList<std::string>& list);
void removeTask(LinkedList<std::string>& list);
void clearTasks(LinkedList<std::string>& list);

int main(int argc, const char* argv[]) {
    LinkedList<std::string> list;
    int menuChoice;

    do {
        menuChoice = getMenuChoice();

        switch (menuChoice) {
            case 1:
                insertTask(list);
                break;
            case 2:
                removeTask(list);
                break;
            case 3:
                list.print();
                break;
            case 4:
                clearTasks(list);
                break;
            case 0:
            default:
                break;
        }

    } while (menuChoice != 0);

    return 0;
}

void clearTasks(LinkedList<std::string>& list){
    if (!list.isEmpty()) {
        list.clear();
        std::cout << "List cleared." << std::endl;
    } else {
        std::cout << std::endl << "There are no tasks in the list." << std::endl;
    }
}

void insertTask(LinkedList<std::string>& list){
    int priority;
    int listLength = list.getLength();
    std::string newTask;

    if (list.isEmpty()) {
        priority = 1;
    } else {
        list.print();
        priority = getTaskPriority(listLength);
    }

    std::cout
        << "What is your new task?" << std::endl
        << "Enter task: ";

    std::getline(std::cin >> std::ws, newTask);

    if (list.insert(priority, newTask)) {
        std::cout << "Task '" << newTask << "' successfully inserted." << std::endl;
    } else {
        std::cout << "Error: Task not successfully inserted." << std::endl;
    }
}

void removeTask(LinkedList<std::string>& list){
    int listLength = list.getLength();
    int taskNumber;
    list.print();

    if (list.isEmpty()) {
        return;
    }

    std::cout
        << "Which task are you removing?" << std::endl
        << "Enter the task number (1-" << listLength << "): ";

    std::cin >> taskNumber;

    while (std::cin.fail() || (taskNumber < 1 || taskNumber > listLength)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout
            << "Error: Invalid input." << std::endl
            << "Enter the task number (1-" << listLength << "): ";

        std::cin >> taskNumber;
    }

    if (list.remove(taskNumber)) {
        std::cout << std::endl << "Removed task." << std::endl;
    } else {
        std::cout << "Error: No task removed.";
    }
}

int getTaskPriority(int listLength) {
    int taskPriority = -1;

    std::cout
        << "Info: Task priority must be between " << 1 << " and " << listLength + 1 << std::endl
        << "What is the priority of your new task?" << std::endl
        << "Enter priority: ";

    std::cin >> taskPriority;

    while (std::cin.fail() || (taskPriority < 1 || taskPriority > listLength + 1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout
            << std::endl
            << "Error: Invalid task priority." << std::endl
            << "Enter priority: ";

        std::cin >> taskPriority;
    }

    return taskPriority;
}

int getMenuChoice() {
    int choice = -1;

    std::cout
        << std::endl
        << "To-do List Main Menu" << std::endl
        << "================================" << std::endl
        << "1. Add a new task" << std::endl
        << "2. Delete a task" << std::endl
        << "3. Show all tasks" << std::endl
        << "4. Remove all tasks" << std::endl
        << "0. EXIT" << std::endl
        << std::endl
        << "Enter your choice (0-4): ";

    std::cin >> choice;

    while (std::cin.fail() || (choice < 0 || choice > 4)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout
            << std::endl
            << "Error: Invalid choice."
            << std::endl
            << "Enter your choice (0-4): ";
            
        std::cin >> choice;
    }

    std::cout << std::endl;

    return choice;
}
