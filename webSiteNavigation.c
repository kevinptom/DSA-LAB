#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char url[100];
    struct Node *prev,*next;
};

struct Node *current = NULL;

void visit(char *url){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url,url);
    newNode->prev = current;
    newNode->next = NULL;
    
    if(current){
        struct Node *temp=current->next;
        while(temp){
            struct Node *del=temp;
            temp=temp->next;
            free(del);
        }
        current->next= newNode;
    }
    current = newNode;
}

void back(){
    if(current && current->prev){
        current = current->prev;
        printf("The previous website is %s",current->url);
    }
    else{
        printf("There is no previous website.");
    }
}

void forward(){
    if(current && current->next){
        current = current->next;
        printf("The forwrd website is %s",current->url);
    }
    else{
        printf("There is no forward website.");
    }
}

int main(){
    char url[100];
    int choice;
    printf("=====Website Navigation=====\n1.Visit\n2.Back\n.3Forward\n4.Exit");
    while(1){
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the website:");
                scanf("%s",&url);
                visit(url);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice!");
                break;
        }
    }
}
