#include "llist.h"
#include "arraystack.h"
#include <iostream>

using namespace std;

int main(){
    
    int array[] = {23,-98,56,78,45,100,9,370};
    Node* sampleNode = createListFromArray(array);
    displayList(sampleNode);
    appendNodeToList(sampleNode, 1243);
    displayList(sampleNode);
    appendListToNode(4567, &sampleNode);
    displayList(sampleNode);
    
    Stack* stack = createArrayStack(10);
    stack->push(35);
    stack->push(33);
    stack->push(-34);
    cout << stack->peek() << endl;
    stack->pop();
    stack->pop();
    cout << stack->peek() << endl;
    stack->pop();
    stack->pop();
    cout << stack->peek() << endl;
    return 0;
}


