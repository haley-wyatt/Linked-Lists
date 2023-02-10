/*
Name: Wyatt Haley
Class: Data Structures
File name: linkedlist.cpp
*/

#include "linkedlist.h"

template<class ItemType>
LinkedList<ItemType>::LinkedList(){
    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(int count){
    itemCount = count;
    headPtr = nullptr;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const{
    if(itemCount == 0){
        return true;
    }
    else{
        return false;
    }
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const{
    return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
    if(newPosition > 0 && newPosition <= itemCount+1){

        Node<ItemType>* newNodePtr = new Node<ItemType>();
        Node<ItemType>* curPtr = headPtr;
        if(newPosition == 1){
            newNodePtr->setNext(headPtr);
            newNodePtr->setItem(newEntry);
            headPtr = newNodePtr;
            itemCount++;
            return true;
        }
        else{
            for(int i = 1; i < newPosition-1; i++){
                curPtr = curPtr->getNext();
            }
            newNodePtr->setNext(curPtr->getNext());
            curPtr->setNext(newNodePtr);
            newNodePtr->setItem(newEntry);
            itemCount++;
            return true;
        }
    }
    return false;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position){
    Node<ItemType>* curPtr = headPtr;
    Node<ItemType>* nodeToDeletePtr;
    if(position > 0 && position <= itemCount){
        // case for deleting head node
        if(position == 1){
            nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
            nodeToDeletePtr->setNext(nullptr);
            delete nodeToDeletePtr;
            nodeToDeletePtr = nullptr;
            itemCount--;
            return true;
        }
        else{
            for(int i=1; i<position-1; i++){
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

template<class ItemType>
void LinkedList<ItemType>::clear(){
    for(int i=0;i<=itemCount+1;i++){
        remove(1);
    }
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const{
    Node<ItemType>* curPtr = headPtr;
    for(int i=1;i<position;i++){
        curPtr = curPtr->getNext();
    }
    return curPtr->getItem();
}

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry){
    ItemType tempItem;
    Node<ItemType>* curPtr = headPtr;
    if(position > 0 && position <= itemCount){
        for(int i=0;i<position-1;i++){
            curPtr = curPtr->getNext();
        }
        tempItem = curPtr->getItem();
        curPtr->setItem(newEntry);
        return tempItem;
    }
}

template<class ItemType>
void LinkedList<ItemType>::print(){
    if(headPtr == nullptr){
        std::cout << "No tasks currently!" << std::endl;
        return;
    }
    Node<ItemType>* curPtr = headPtr;
    for(int i = 1; i<itemCount+1; i++){
        std::cout << i << ": " << curPtr->getItem() << std::endl;
        curPtr = curPtr->getNext(); 
    }
}
