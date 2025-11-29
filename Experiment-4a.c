/* Implementation of Queue operations*/

#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;

void enqueue(int q[],int size,int item){
    if(rear == size - 1){
        printf("Overflow!");
    }
    else{
        rear++;
        q[rear] = item;
        printf("The element %d is enqueued.",item);
    }
}

void dequeue(int q[],int size){
    if(front == rear){
        printf("Underflow!");
    }
    else{
        front++;
        printf("The element %d is dequeued",q[front]);
    }
}
void display(int q[],int size){
    if(front == rear){
        printf("\nNow the Queue is empty.");
    }
    else{
        printf("\nCurrent Queue elements are:");
        for(int i=front+1;i<=rear;i++){
            printf("%d ",q[i]);
        }
    }
}
int main() {
    int size;
    printf("Enter the size of the Queue:");
    scanf("%d",&size);
    int queue[size];
    printf("============The Queue operations are:=============\n1.Enqueue\n2.Dequeue\n3.Exit");
    int choice,item;
    while(1){
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to enqueue:");
                scanf("%d",&item);
                enqueue(queue,size,item);
                display(queue,size);
                break;
            case 2:
                dequeue(queue,size);
                display(queue,size);
                break;
            case 3:
                printf("Thank you!");
                exit(0);
            default:
                printf("Invalid choice.");
                break;
            
        }
    }
    return 0;
}
