#include <stdio.h>
#include <stdlib.h> // For exit() if needed, though error messages are used here
#define MAX_SIZE 5 // Define the maximum capacity of the stack

int stack[MAX_SIZE]; // Array to store stack elements
int top = -1; // Index of the top element, initialized to -1 for an empty stack

// Function to check if the stack is empty
int isEmpty() {
    return top == -1; // Returns 1 (true) if empty, 0 (false) otherwise
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1; // Returns 1 (true) if full, 0 (false) otherwise
}

// Function to add an element to the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot add more elements.\n");
    } else {
        stack[++top] = value; // Increment top and insert the value
        printf("%d pushed to stack.\n", value);
    }
}

// Function to remove an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot remove elements from an empty stack.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        int popped_value = stack[top]; // Get the top element
        top--; // Decrement top
        return popped_value;
    }
}

// Function to view the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty! No top element to display.\n");
        return -1; // Return a sentinel value
    } else {
        return stack[top]; // Return the top element
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60); // This will cause a Stack Overflow message

    printf("\nTop element is %d.\n", peek());

    printf("\nPopped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("\nElements remaining in the stack:\n");
    while (!isEmpty()) { // Print remaining elements
        printf("%d\n", pop());
    }

    return 0;
}
