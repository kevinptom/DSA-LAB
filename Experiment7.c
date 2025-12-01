/* Polynomial Addition*/

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coefficient;
    int exponent;
    struct Node *next;
};

int main() {
   struct Node *poly1 = NULL;
   struct Node *poly2 = NULL;
   
   struct Node *temp1= NULL,*temp2 = NULL;
   int term1,term2;
   int coef,expo;
   
   printf("Enter the number of terms in polynomial1 ");
   scanf("%d",&term1);
   printf("Enter the number of terms in polynomial2 ");
   scanf("%d",&term2);
   
   //reading first polynomial
   printf("Enter the coefficient and exponent of each term in Polynomial1\n");
   for(int i=0;i<term1;i++){
       printf("Term %d:",i);
       scanf("%d%d",&coef,&expo);
       struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
       if(poly1 == NULL){
           newNode->coefficient = coef;
           newNode->exponent = expo;
           newNode->next = NULL;
           poly1=newNode;
       }
       else{
           temp1 = poly1;
           while(temp1->next!=NULL){
               temp1 = temp1->next;
           }
           newNode->coefficient = coef;
           newNode->exponent = expo;
           temp1->next = newNode;
       }
   }
   printf("Enter the coefficient and exponent of each term in Polynomial2\n");
   int coef2,expo2;
   for(int i=0;i<term2;i++){
       printf("Term %d:",i);
       scanf("%d%d",&coef,&expo);
       struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
       if(poly2 == NULL){
           newNode->coefficient = coef;
           newNode->exponent = expo;
           newNode->next = NULL;
           poly2=newNode;
       }
       else{
           temp2 = poly2;
           while(temp2->next!=NULL){
               temp2 = temp2->next;
           }
           newNode->coefficient = coef;
           newNode->exponent = expo;
           temp2->next = newNode;
       }
   }
   
   //Performing addition
   struct Node *result=NULL,*tempResult=NULL;
   temp1 = poly1;
   temp2 = poly2;
   
   while(temp1!=NULL && temp2!=NULL){
       int coef=0,expo=0;
       
       if(temp1 == NULL){
           coef = temp2->coefficient;
           expo = temp2->exponent;
           temp2= temp2->next;
       }
       
       else if(temp2 == NULL){
           coef = temp1->coefficient;
           expo = temp1->exponent;
           temp1= temp1->next;
       }
       
       else if(temp1->exponent > temp2->exponent){
           coef = temp1->coefficient;
           expo = temp1->exponent;
           temp1 = temp1->next;
       }
       else if(temp1->exponent < temp2->exponent){
           coef = temp2->coefficient;
           expo = temp2->exponent;
           temp2 = temp2->next;
       }
       else{
           coef = temp1->coefficient + temp2->coefficient;
           expo = temp1->exponent;
           temp1 = temp1->next;
           temp2 = temp2->next;
       }
       
       struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
       
       newNode->coefficient=coef;
       newNode->exponent=expo;
       newNode->next = NULL;
       
       if(result ==NULL) {
           result = newNode;
       }
       else{
           tempResult = result;
           while(tempResult->next != NULL){
               tempResult=tempResult->next;
           }
           tempResult->next = newNode;
       }
        
   }
   printf("The sum of polynomials is:");
   tempResult=result;
   while(tempResult != NULL){
       printf("%dx^%d",tempResult->coefficient,tempResult->exponent);
       if(tempResult->next != NULL){
           printf(" + ");
       }
       tempResult = tempResult->next;
   }
}
