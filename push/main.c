#include <stdio.h>
#include <stdlib.h>

void push(){
     info *newptr;
     newptr =(info*)malloc(sizeof(info)) ;
     if(top==NULL){
      top = newptr ;
        newptr->link=NULL;
        }
        else{
            newptr->link=top;
            top=newptr;
            }
     printf("Please ,Enter the code of product \n");
       scanf("%d",&(top->code));
       printf("Please ,Enter the Name of product \n");
       scanf("%s",&(top->name));
       printf("Please ,Enter the price of \n");
       scanf("%d",&(top->price));
       printf("Please ,Enter the number of product \n");
       scanf("%d",&(top->number));

}
