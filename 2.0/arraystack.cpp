#include <iostream>
#include "arraystack.h"

struct Stack* createArrayStack(int capacity){
    struct Stack* newArrayStack = (struct Stack*) new struct Stack;
    if (!newArrayStack)
        return NULL;
    newArrayStack->capacity = capacity;
    newArrayStack->top = -1;
    newArrayStack->arrayStack = new int[newArrayStack->capacity];
    if ( !newArrayStack->arrayStack)
        return NULL;
    return newArrayStack;
}

bool Stack::isStackFull(){
	return this->top == this->capacity-1;
}

bool Stack::isStackEmpty(){
	return this->top == -1;
}

void Stack::push(int data){
	//lets check if the stack is full, if so, throw an error
	if(isStackFull()){
		std::cout << "Exception: StackOverflow" << std::endl;
		exit(-1);
	}
	else
		this->arrayStack[++this->top] = data;
}

int Stack::pop(){
	//lets check if the stack is empty, if so, throw an error
	if(isStackEmpty()){
		std::cout << "Exception: Stack is Empty" << std::endl;
		exit(-1);
	}
	else
		return this->arrayStack[this->top--];
}

int Stack::peek(){
	//lets check if the stack is empty, if so, throw an error
	if(isStackEmpty()){
		std::cout << "Exception: Stack is Empty" << std::endl;
		exit(-1);
	}
	else
		return this->arrayStack[this->top];
}