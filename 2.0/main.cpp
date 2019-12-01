#include "llist.h"
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
    return 0;
}


