/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Linked list class, provides the functionality to create a linked
                list then append, insertm edit, search, and display the list.
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#include <iostream>
#include <stdio.h>

#ifndef LIST_H
#define LIST_H

template <class T>
class List {
    
    private:
        
        struct Node {
            T value;
            Node *next;
        };
        
        Node *head;
        
    public:
        List()
        {head = nullptr;}
        
        //~List();  //code would not function properly with the destructor
        
        void appendNode(T);
        void insertNode(T);
        void deleteNode(T);
        void editNode(T,int);
        void displayList();
        int searchList(T);
        bool isEmpyty();
        T getNode(int);
        T sum();
    
};

//adds the node passed in to the end of the list
template <class T>
void List<T>::appendNode(T newValue) {
    Node *newNode;
    Node *nodePtr;
    
    newNode = new Node;
    newNode -> value = newValue;
    newNode -> next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        nodePtr = head;
        while (nodePtr -> next) {
            nodePtr = nodePtr -> next;
        }
        nodePtr -> next = newNode;
    }
}

//inserts a node in order from least to greatest
template <class T>
void List<T>::insertNode(T newValue) {
    Node *newNode;
    Node *nodePtr;
    Node *previousNode;
    
    newNode = new Node;
    newNode -> value = newValue;
    
    if (!head) {
        head = newNode;
        newNode -> next = nullptr;
    } else {
        nodePtr = head;
        previousNode = nullptr;
        
        while (nodePtr != nullptr && nodePtr -> value < newValue) {
            previousNode = nodePtr;
            nodePtr = nodePtr -> next;
        }
        
        if (previousNode == nullptr) {
            head = newNode;
            newNode -> next = nodePtr;
        } else {
            previousNode -> next = newNode;
            newNode -> next = nodePtr;
        }
    }
}

//delete a node from the list
template <class T>
void List<T>::deleteNode(T searchValue) {
    if (!head) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    Node *nodePtr;
    Node *previousNode;
    
    if (head -> value == searchValue) {
        nodePtr = head -> next;
        delete head;
        head = nodePtr;
    } else {
        nodePtr = head;
        
        while (nodePtr != nullptr && nodePtr -> value != searchValue) {
            previousNode = nodePtr;
            nodePtr = nodePtr -> next;
        }
        
        if (nodePtr) {
            previousNode -> next = nodePtr -> next;
            delete nodePtr;
        } else {
            std::cout << "Value not found!" << std::endl;
        }
    }
}

//allows the user to replace a node
template <class T>
void List<T>::editNode(T newNode, int index) {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
    }
    
    Node *nodePtr = head;
    int count = 0;
    while (nodePtr) {
        if (count == index) {
            nodePtr -> value = newNode;
        } else {
            count++;
            nodePtr = nodePtr -> next;
        }
    }
    T outOfBounds;
}

//output the contents of the list
template <class T>
void List<T>::displayList() {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    
    Node *nodePtr = head;
    
    while (nodePtr != nullptr) {
        std::cout << &nodePtr -> value << std::endl;
        nodePtr = nodePtr -> next;
    }   
}

//search the list for a node
template <class T>
int List<T>::searchList(T searchValue) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
    } else if (head -> value == searchValue) {
        return 0;
    }
    
    Node *nodePtr;
    int index = 0;
    
    while (nodePtr) {
        if (nodePtr -> value == searchValue) {
            return index;
        } else {
            index++;
            nodePtr = nodePtr -> next; 
            if (nodePtr == nullptr) {
                //proper output only worked with
                //empty if statement... ¯\_(ツ)_/¯
            }
        }
    }
    std::cout << "Value not found!" << std::endl;
    return -1;
}

//return a node based on its index value
template <class T>
T List<T>::getNode(int index) {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return head->value;
    }
    
    Node *nodePtr = head;
    int count = 0;
    while (nodePtr) {
        if (count == index) {
            return nodePtr -> value;
        } else {
            count++;
            nodePtr = nodePtr -> next;
        }
    }
    T outOfBounds;
    return outOfBounds;
}

//check if the list is empty
template <class T>
bool List<T>::isEmpyty() {
    if (!head) {
        return true;
    } else {
        return false;
    }
}
/*
template <class T>
List<T>::~List() {
    Node *nodePtr;
    Node *nextNode;
    
    nodePtr = head;
    
    while (nodePtr) {
        nextNode = nodePtr -> next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}
*/

//sum the contents of the node
template <class T>
T List<T>::sum() {
    Node *nodePtr = head;
    T temp;
    while (nodePtr) {
        temp += nodePtr -> value;
        nodePtr = nodePtr -> next;
    }
    return temp;
}
#endif /* LIST_H */

