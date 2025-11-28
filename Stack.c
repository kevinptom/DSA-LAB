/* Normal Stack Implementation */

#include <stdio.h>
#include <stdlib.h>

#define Max_Size 100

int stack[Max_Size];
int top = -1;

void push(int item){
    if(top == Max_Size-1){
        printf("Overflow!");
    }
    else{
        top++;
        stack[top] = item;
        printf("Element %d is pushed on to the stack",item);
    }
}
void pop(){
    if(top == -1){
        printf("Underflow!");
    }
    else{
        int popItem = stack[top];
        top--;
        printf("The element %d is deleted from the stack",popItem);
    }
}
void display(){
    if(top == -1){
        printf("Underflow!");
    }
    else{
        printf("\nStack elements are:");
        for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
    }
}

int main() {
    printf("\n==================The Stack Operations are================");
    printf("\n1.Push\n2.Pop\n3.Exit");
    int choice;
    while(1){
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
        int item;
        switch(choice){
            case 1:
                
                printf("Enter the element to push into the stack:");
                scanf("%d",&item);
                push(item);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid Choice!");
                break;
                
        }
    }
}
