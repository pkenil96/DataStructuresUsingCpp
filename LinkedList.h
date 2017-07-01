#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node* NODE;

NODE createNode(int data){
    NODE newNode = (NODE) malloc (sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return (newNode);
}

void insertIntoBeginning(NODE* head, int data){
    NODE newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
    return;
}

void insertAtEnd(NODE* head, int data){
    NODE newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return ;
    }

    NODE temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return;
}

void insertAtN(NODE* head, int data, int pos){
    NODE newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    int count = 0;

}

void displayList(NODE head){

    if(head == NULL){
        cout <<"List is empty"<<endl;
        return;
    }

    cout << "Content of the linked list:"<<endl;
    NODE temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int iterative_lenght_of_list(NODE head){

    if(head == NULL)
        return 0;

    int length = 0;
    NODE temp = head;

    while(temp){
    temp = temp->next;
    length++;
    }


 return length;
}

int recursive_lenght_of_list(NODE head){
    static int length =0;

    if(head == NULL)
        return length;

    length++;
    recursive_lenght_of_list(head->next);
}
