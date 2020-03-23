#ifndef ARRAYSTACK
#define ARRAYSTACK

struct Stack{

    int top; 
    int capacity; 
    int* arrayStack;

	// pushes the new element on to the stack
	void push(int);
	// returns the topmost element and delete from the stack
	int pop();
	//returns the topmost element without deleting it
	int peek();
	//check if the stack if empty
	bool isStackEmpty();
	//check if the stack is full
	bool isStackFull();
};
#endif

// creates a new array stack with given capacity
struct Stack* createArrayStack(int);
