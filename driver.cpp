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
// getMenuChoice displays the main menu and receives and returns the chosen option
int getMenuChoice(){
	int choice;
	do {
        std::cout << std::endl << "TODO Application" << std::endl;
        std::cout << "================================" <<std::endl;
        std::cout.width(8); std::cout << std::left << "1.";
		std::cout.width(8); std::cout << std::left << "Add a new task" << std::endl;
		std::cout.width(8); std::cout << std::left << "2.";
        std::cout.width(8); std::cout << std::left << "Delete a task" << std::endl;
        std::cout.width(8); std::cout << std::left << "3.";
        std::cout.width(8); std::cout << std::left << "Show all tasks" << std::endl;
        std::cout.width(8); std::cout << std::left << "4.";
        std::cout.width(8); std::cout << std::left << "Remove all tasks" << std::endl;
        std::cout.width(8); std::cout << std::left << "0.";
        std::cout.width(8); std::cout << std::left << "EXIT" << std::endl;
		std::cin >> choice;
	}while(choice !=0 && choice !=1 && choice !=2 && choice !=3 && choice !=4);
	return choice;
}
