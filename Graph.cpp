#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

struct ListNode{
    int vertexNumber;
    struct ListNode* next;
};

struct Graph{
    int V;
    int E;
    struct ListNode* adj;
};

struct Graph* createGraph(int V){
    struct Graph* newGraph = new Graph();
    newGraph->V = V;
    newGraph->adj = new ListNode[V];
    
    //Initializing the adjacency list with the vertices
    for(int i=0;i<V;i=i+1){
        (newGraph->adj+i)->vertexNumber = i; // or newGraph->adj[i].vertexNumber = i;
        (newGraph->adj+i)->next = NULL; // or newGraph->adj[i].next = NULL;
    }

    return newGraph;
}

void addEdge(struct Graph* graph, int src, int des){
    struct ListNode* srcNode = new ListNode;
    struct ListNode* desNode = new ListNode;
    
    srcNode->vertexNumber = src;
    srcNode->next = NULL;
    desNode->vertexNumber = des;
    desNode->next = NULL;

    struct ListNode* temp;

/*appending src node to the des node*/
    temp = graph->adj+src;
    while(temp->next)
        temp = temp->next;

    temp->next = desNode;
    desNode->next = NULL;

/*appending des node to the src node*/
    temp = graph->adj+des;
    while(temp->next)
        temp = temp->next;

    temp->next = srcNode;
   srcNode->next = NULL;
}

void displayGraph(struct Graph* graph){
    struct ListNode* temp;
    for(int i=0;i<graph->V;i++){
        temp = graph->adj+i;

        while(temp){
            cout << temp->vertexNumber << "->";
            temp = temp->next;
        }
        cout << "NULL";
        cout << endl;
    }
}


int main(int argc, char* argv[]){


	int n,m,a,b;
	cin >> n >> m;

    struct Graph* G;
    G = createGraph(n+1);
    
    if(G==NULL){
    	cout << "Couldn't allocate memory for graph!" << endl;
    	exit(-1);
    }

    for(int i=0;i<m;i++){
    	cin >> a >> b;
    	addEdge(G,a,b);
    }
    displayGraph(G);

    return 0;
    
}
