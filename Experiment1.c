// Polynomial addition using arrays

#include <stdio.h>
struct polynomial{
    int coef;
    int expo;
};

int main() {
    int n1,n2;
    int k=0,i=0,j=0;
    printf("Enter the number of terms in polynomial 1:");
    scanf("%d",&n1);
    printf("Enter the number of terms in polynomial 2:");
    scanf("%d",&n2);
    struct polynomial poly1[n1];
    struct polynomial poly2[n2];
    struct polynomial result[n1 + n2];
    
    printf("Enter the coefficient and exponent of polynomial1 in descending order");
    for(int i=0; i<n1 ; i++){
        scanf("%d%d",&poly1[i].coef,&poly1[i].expo);
    }
    printf("Enter the coefficient and exponent of polynomial2 in descending order");
    for(int j=0; j<n2 ; j++){
        scanf("%d%d",&poly2[j].coef,&poly2[j].expo);
    }
    
    while(i < n1 && j < n2){
        
        if(poly1[i].expo == poly2[j].expo){
            result[k].coef = poly1[i].coef + poly2[j].coef;
            result[k].expo = poly1[i].expo;
            i++;j++;k++;
        }
        
        else if(poly1[i].expo > poly2[j].expo){
            result[k].coef = poly1[i].coef;
            result[k].expo = poly1[i].expo;
            i++;k++;
        }
        
        else{
            result[k].coef = poly2[j].coef;
            result[k].expo = poly2[j].expo;
            j++;k++;
        }
    }
    
    while(i < n1){
        result[k] = poly1[i];
        i++;k++;
    }
    while(j < n2){
        result[k] = poly2[j];
        j++;k++;
    }
    printf("The resultant polynomial is:");
    for(int i=0; i<k ; i++){
        printf("%dx^%d",result[i].coef,result[i].expo);
        if(i!= k-1){
            printf(" + ");
        }
    }
    
    return 0;
}
