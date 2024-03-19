/*
Name: Wyatt Haley
Class: Data Structures
File name: linkedlist.h
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listinterface.h"
#include "node.h"

template<class ItemType>
class LinkedList {
private:
    Node<ItemType>* headPtr;
    int itemCount;
public:
    LinkedList();
    LinkedList(int count);
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    ItemType replace(int position, const ItemType& newEntry);
    void print();
    ~LinkedList() { clear(); }
};

template <class ItemType>
LinkedList<ItemType>::LinkedList() {
    itemCount = 0;
    headPtr = nullptr;
}

template <class ItemType>
LinkedList<ItemType>::LinkedList(int count) {
    itemCount = count;
    headPtr = nullptr;
}

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return itemCount == 0 ? true : false;
}

template <class ItemType>
int LinkedList<ItemType>::getLength() const {
    return itemCount;
}

template <class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry) {
    if (newPosition > 0 && newPosition <= itemCount + 1) {
        Node<ItemType>* newNodePtr = new Node<ItemType>();
        Node<ItemType>* curPtr = headPtr;

        if (newPosition == 1) {
            newNodePtr->setNext(headPtr);
            newNodePtr->setItem(newEntry);
            headPtr = newNodePtr;
            itemCount++;

            return true;
        } else {
            for (int i = 1; i < newPosition - 1; i++) {
                curPtr = curPtr->getNext();
            }
            newNodePtr->setNext(curPtr->getNext());
            curPtr->setNext(newNodePtr);
            newNodePtr->setItem(newEntry);
            itemCount++;

            return true;
        }

    } else {
        std::cout << "Insertion into list must be between 1 and " << (itemCount + 1);
    }

    return false;
}

template <class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    Node<ItemType>* curPtr = headPtr;
    Node<ItemType>* nodeToDeletePtr;

    if ((position > 0) && (position <= itemCount)) {
        if (position == 1) { // case for deleting head node
            nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
            nodeToDeletePtr->setNext(nullptr);
            delete nodeToDeletePtr;
            nodeToDeletePtr = nullptr;
            itemCount--;

            return true;
        } else {
            for (int i = 1; i < position - 1; i++) {
                curPtr = curPtr->getNext();
            }
            nodeToDeletePtr = curPtr->getNext();
            curPtr->setNext(nodeToDeletePtr->getNext());
            delete nodeToDeletePtr;
            nodeToDeletePtr = nullptr;
            itemCount--;

            return true;
        }
    }

    return false;
}

template <class ItemType>
void LinkedList<ItemType>::clear() {
    for (int i = 0; i <= itemCount + 1; i++) {
        remove(1);
    }
}

template <class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const {
    Node<ItemType>* curPtr = headPtr;
    for (int i = 1; i < position + 1; i++) {
        curPtr = curPtr->getNext();
    }
    return curPtr->getItem();
}

template <class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) {
    ItemType tempItem;
    Node<ItemType>* curPtr = headPtr;

    if (position > 0 && position <= itemCount) {
        for (int i = 0; i < position - 1; i++) {
            curPtr = curPtr->getNext();
        }
        tempItem = curPtr->getItem();
        curPtr->setItem(newEntry);

        return tempItem;
    }
}

template <class ItemType>
void LinkedList<ItemType>::print() {
    if (headPtr == nullptr) {
        std::cout << std::endl << "There are no tasks in the list." << std::endl;
        return;
    }

    std::cout << std::endl << "Current task list: " << std::endl;

    Node<ItemType>* curPtr = headPtr;

    for (int i = 1; i < itemCount + 1; i++) {
        std::cout << i << ": " << curPtr->getItem() << std::endl;
        curPtr = curPtr->getNext();
    }
}

#endif //LINKEDLIST_H
