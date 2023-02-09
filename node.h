/*
Name: Wyatt Haley
Class: CS 302 w/ Erin Keith
Date: 09/27/2022
Programming Assignment 2
File name: node.h
*/

#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node{
    private:
        ItemType item; 
        Node<ItemType>* next; // Points to next node
    public:
        
        Node();
        Node(const ItemType& anItem);
        Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
        void setItem(const ItemType& anItem);
        void setNext(Node<ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getNext() const;
};
#include "node.cpp"
#endif