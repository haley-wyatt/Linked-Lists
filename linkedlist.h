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
#include "linkedlist.cpp"
#endif
