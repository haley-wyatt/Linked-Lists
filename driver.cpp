/*
Name: Wyatt Haley
Class: Data Structures
File name: driver.cpp
*/

#include "linkedlist.h"

int getMenuChoice();

int main(int argc, const char* argv[]){

    LinkedList<std::string> linkedList;
    int menuChoice = 0;
    int choice = 0;
    std::string newTask;
    
    do{
        menuChoice = getMenuChoice();
        switch (menuChoice){
            case 0:
                break;
            case 1: // add a new task to linked list
                linkedList.print();
                std::cout << "What is the priority of your new task?" << std::endl;
                std::cin >> choice;
                std::cout << "What is your new task?" << std::endl;
                std::getline(std::cin >> std::ws, newTask);
                linkedList.insert(choice, newTask);
                break;
            case 2: // remove a task from linked list
                linkedList.print();
                std::cout << "Which task are you removing?" << std::endl;
                std::cin >> choice;
                std::cout << "Removed: " << linkedList.getEntry(choice) << std::endl;
                linkedList.remove(choice);
                break;
            case 3: // print linked list
                linkedList.print();
                break;
            case 4: // clear linked list
                linkedList.clear();
                std::cout << "List cleared." << std::endl;
                break;
            default:
                break;  
        }
    } while (menuChoice != 0);

    return 0;
}

int getMenuChoice(){
	int choice -1;
	do {
		std::cout << std::endl << "To-do List" << std::endl;
		std::cout << "================================" << std::endl;
		std::cout << "1. " << "Add a new task" << std::endl;
		std::cout << "2. " << "Delete a task" << std::endl;
		std::cout << "3. " << "Show all tasks" << std::endl;
		std::cout << "4. " << "Remove all tasks" << std::endl;
		std::cout << "0. " << "EXIT" << std::endl;
		std::cin >> choice;
	} while(choice < 0 || choice > 4);
	return choice;
}
