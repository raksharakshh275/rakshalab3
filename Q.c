#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 // Define the maximum size of the queue

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function prototypes
void enqueue(int data);
int dequeue();
int isEmpty();
int isFull();
void display();

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    display();

    printf("\nElement removed from queue: %d\n", dequeue());
    printf("Element removed from queue: %d\n", dequeue());
    
    display();
    
    enqueue(50);
    enqueue(60); // This will show a "Queue is Full" message

    display();

    return 0;
}

// Check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Check if the queue is full
int isFull() {
    return rear == MAX_SIZE - 1;
}

// Add an element to the queue (Enqueue operation)
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is Full! Cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty()) {
        front = 0; // Set front to 0 when the first element is inserted
    }
    rear++;
    queue[rear] = data;
    printf("Enqueued: %d\n", data);
}

// Remove an element from the queue (Dequeue operation)
int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty! Cannot dequeue\n");
        return -1; // Return a sentinel value for error
    }
    int data = queue[front];
    if (front >= rear) {
        // Queue becomes empty after this dequeue, reset pointers
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return data;
}

// Display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
