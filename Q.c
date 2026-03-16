#include <stdio.h>
#include <stdlib.h>
<<<<<<< 4c2aee09e4391076f373d457fc2a49cf00106179
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

=======
#define MAX_SIZE 10 // Maximum size of the queue

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue(int);
void dequeue();
void display();
void search(int);
int isEmpty();
int isFull();

int main() {
    int choice, value;

    while (1) {
        printf("\n-------- Queue Operations Menu --------\n");
        printf("1. Enqueue (Insert element)\n");
        printf("2. Dequeue (Delete element)\n");
        printf("3. Display the Queue\n");
        printf("4. Search for an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
>>>>>>> Added Q.c file
    return 0;
}

// Check if the queue is empty
int isEmpty() {
<<<<<<< 4c2aee09e4391076f373d457fc2a49cf00106179
    return front == -1 || front > rear;
=======
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
>>>>>>> Added Q.c file
}

// Check if the queue is full
int isFull() {
<<<<<<< 4c2aee09e4391076f373d457fc2a49cf00106179
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
=======
    if (rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

// Add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow: Cannot add more elements, the queue is full.\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

// Remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow: Cannot delete elements, the queue is empty.\n");
    } else {
        printf("Deleted element %d from the queue.\n", queue[front]);
        front++;
        // Reset front and rear if the queue becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// Display all elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Search for a specific element in the queue
void search(int value) {
    if (isEmpty()) {
        printf("Queue is empty. Cannot search for elements.\n");
        return;
    }

    int found = 0;
    int index = -1;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == value) {
            found = 1;
            index = i - front + 1; // Position from the front (1-based index)
            break;
        }
    }

    if (found) {
        printf("Element %d found at position %d in the queue.\n", value, index);
    } else {
        printf("Element %d not found in the queue.\n", value);
    }
}

>>>>>>> Added Q.c file
