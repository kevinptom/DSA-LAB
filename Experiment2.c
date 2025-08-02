#include <stdio.h>

int main() {
    int n = 5; 
    int queue[n];
    int front = 0, rear = 0;
    char ch;
    int data;

    
    void enqueue() {
        printf("Enter number to enqueue: ");
        scanf("%d", &data);
        
        if (rear == n) {
            printf("Queue is full.\n");
        } else {
            queue[rear] = data;
            rear = rear + 1;
            printf("Queue: ");
            for (int i = 0; i < rear; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }

    
    void dequeue() {
        if (front == rear) {
            printf("Queue is empty.\n");
        } else {
      
            printf("Dequeued: %d\n", queue[front]);
            front = front + 1; 
            printf("Queue after dequeue: ");
            for (int i = front; i < rear; i++) {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }
   printf("The choices are:");
   printf("\n1. Enqueue\n2. Dequeue\n3. Exit\n"); 
    
  while (1) {
        printf("Enter your choice:");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;  
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
        

        printf("Do you want to continue (Y/N): ");
        scanf(" %c", &ch);  

        if (ch == 'N' || ch == 'n') {
            printf("Exiting program...\n");
            break;  
        }
    }
    return 0;
}
