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

int main(int argc, const char* argv[]) {

    LinkedList<std::string> linkedList;
    int menuChoice, taskNumber, taskPriority;
    std::string newTask;

    do {
        int listLength = linkedList.getLength();
        menuChoice = getMenuChoice();

        switch (menuChoice) {
        case 1: // add a new task to linked list
            // determine task priority
            if (linkedList.isEmpty()) {
                taskPriority = 1;
            } else {
                linkedList.print();
                taskPriority = getTaskPriority(listLength);
            }

            // get task definition
            std::cout
                << "What is your new task?" << std::endl
                << "Enter task: ";

            std::getline(std::cin >> std::ws, newTask);

            // check for successful insertion into linked list
            if (linkedList.insert(taskPriority, newTask)) {
                std::cout << "Task '" << newTask << "' successfully inserted." << std::endl;
            } else {
                std::cout << "Error: Task not successfully inserted." << std::endl;
            }

            break;
        case 2: // remove a task from linked list
            linkedList.print();

            if (linkedList.isEmpty()) {
                break;
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

            if (linkedList.remove(taskNumber)) {
                std::cout << std::endl << "Removed task." << std::endl;
            } else {
                std::cout << "Error: No task removed.";
            }

            break;
        case 3: // print linked list
            linkedList.print();
            break;
        case 4: // clear linked list
            if (!linkedList.isEmpty()) {
                linkedList.clear();
                std::cout << "List cleared." << std::endl;
            } else {
                linkedList.print();
            }

            break;
        case 0:
        default:
            break;
        }

    } while (menuChoice != 0);

    return 0;
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
