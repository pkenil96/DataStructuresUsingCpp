#include <iostream>

struct Node{
    int data;
    struct Node* next;
};

//typedef struct Node* NODE;

Node* createNode(int);

Node* createListFromArray(int*);

void displayList(Node*);

void appendNodeToList(Node*, int);

void appendListToNode(int data, Node**);


