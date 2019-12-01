#include <iostream>
#include "llist.h"

Node* createNode(int data){
    try{
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    } catch(...){
        std::cout << "Cannot allocate memory...Aborting" << std::endl;
        exit(-1);
    }
}

/*
    Returns pointer to the head of the linked list
    formed using the elements contained in the array.
*/
Node* createListFromArray(int* array){
    Node* head = createNode(*array);
    int len = sizeof(array);
    Node* tempNode = head;
    for(int i=1; i<len; i++){
        Node* newNode = createNode(*(array+i));
        tempNode->next = newNode;
        tempNode = newNode;
    }
    return head;
}

void appendNodeToList(Node* head, int data){
    if(!head) 
        return;

    Node* tempNode = head;
    while(tempNode->next){
        tempNode=tempNode->next;
    }
    tempNode->next=createNode(data);
    return;
}

void appendListToNode(int data, Node** head){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    return;
}

void displayList(Node* head){
    Node* tempNode = head;
    while(tempNode){
        std::cout << tempNode->data << " ";
        tempNode=tempNode->next;
    }
    std::cout << std::endl;
}
