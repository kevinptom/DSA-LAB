#include <stdio.h>
#include <stdlib.h>

int rear = -1;
int front = -1;

void enQueue(int q[], int item, int MAX) {
    if (rear == MAX - 1) {
        printf("The queue is full\n");
        return;
    }

    rear++;
    q[rear] = item;

    if (front == -1) {
        front = 0;
    }

    printf("Item %d enqueued.\n", item);
}

void deQueue(int q[]) {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
        return;
    }

    printf("The element deleted is %d\n", q[front]);
    front++;

    // Reset queue if it becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

void display(int q[]) {
    printf("\n");

    if (rear == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("The queue is: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int MAX;
    printf("Enter the size of the Queue: ");
    scanf("%d", &MAX);

    if (MAX <= 0) {
        printf("Invalid queue size.\n");
        return 1;
    }

    int queue[MAX];
    int n;

    while (1) {
        printf("\nEnter the operation required\n");
        printf("=====================================\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("=====================================\n");

        printf("Choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1: {
                printf("Enter the item to enqueue: ");
                int item;
                scanf("%d", &item);
                enQueue(queue, item, MAX);
                display(queue);
                break;
            }
            case 2:
                deQueue(queue);
                display(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("\n======== Program terminated ========\n");
                exit(0);
            default:
                printf("Invalid selection\n");
        }
    }

    return 0;
}
