#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

struct Node{

    int data;
    int key;
    struct Node* right;
    struct Node* left;
};

typedef struct Node* T_NODE;

T_NODE createNode(int data){

    T_NODE newNode = new Node;
    if(!newNode){
        std::cout<<"Not enough memory"<<std::endl;
        exit(-1);
    }
    newNode->data = data;
    return (newNode);
}

void insertNode(T_NODE* head,int data){

        T_NODE newNode = createNode(data);
        T_NODE hold_the_head = *head;
        if(*head == NULL){
            *head = newNode;
            return;
        }

        while(1){

            if( (newNode->data > (*head)->data) && ( (*head)->right == NULL ) ){
                (*head)->right = newNode;
                *head = hold_the_head;
                return;
            }
            else if( newNode->data > (*head)->data ){
                (*head) = (*head)->right;
            }

            else if( (newNode->data < (*head)->data) && ( (*head)->left == NULL ) ){
                (*head)->left = newNode;
                *head = hold_the_head;
                return;
            }
            else if( newNode->data < (*head)->data ){
                (*head) = (*head)->left;
            }
        }
}

void inOrderTraversal(T_NODE node){

    if(node == NULL)
        return;
    inOrderTraversal(node->left);
    std::cout<<node->data<<"\t";
    inOrderTraversal(node->right);
}

void postOrderTraversal(T_NODE node){

    if(node == NULL)
        return;
    inOrderTraversal(node->left);
    inOrderTraversal(node->right);
    std::cout<<node->data<<"\t";
}


void preOrderTraversal(T_NODE node){

    if(node == NULL)
        return;
    std::cout<<node->data<<"\t";
    inOrderTraversal(node->left);
    inOrderTraversal(node->right);
}



int FIND_NODE_COUNT(T_NODE node){
    if(node)
        return 1+FIND_NODE_COUNT(node->left)+FIND_NODE_COUNT(node->right);
     else
        return 0;
}

int FIND_LEAF_NODES_COUNT(T_NODE node){

    if(node == NULL)
        return 0;
    else if(node->left == NULL && node->right == NULL)
            return 0;
     else
            return 1+FIND_LEAF_NODES_COUNT(node->right)+FIND_LEAF_NODES_COUNT(node->left);
}

void Level_Order_Traversal(T_NODE node){

        std::queue <T_NODE> Q;
        Q.push(node);
        while(!Q.empty()){
            T_NODE temp = Q.front();
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
            cout << temp->data <<"\t";
            Q.pop();
        }
}




/*
    --Printing the tree boundary
*/
void Print_Leaves(T_NODE node){
    if(!node)
        return;

    Print_Leaves(node->left);
    if(!(node->right) && !(node->left))
            cout << node->data << " ";
    Print_Leaves(node->right);
}

void Print_Left_Subtree(T_NODE node){

    if(!node) return;

    if( !(node->left) && !(node->right))
        return;

    cout << node->data <<" ";
    if(node->left)
        Print_Left_Subtree(node->left);
    else if(node->right)
        Print_Left_Subtree(node->right);

}


void Print_Right_Subtree(T_NODE node){

    if(!node) return;

    if(!(node->left) && !(node->right))
        return;

    if(node->right)
        Print_Right_Subtree(node->right);
    else if(node->left)
        Print_Right_Subtree(node->left);

    cout << node->data <<" ";


}

void PRINT_BOUNDARY_NODES(T_NODE head){
    Print_Left_Subtree(head);
    Print_Leaves(head);
    Print_Right_Subtree(head);
}
