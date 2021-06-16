
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 typedef struct   {
int code ;
char name[25];
int price ;
int number;
struct  info *link ;

}info;
info *top=NULL, *ptr;
 FILE *fptr;
 info item;
void push();
void display();
void pop(int del);
void search(int a);
void modify(int a);
void storedata();
void clear();
void read();

int main() {
 info *fre;
    read();

    int ch,ch2, ch3 ;
    while(1){
    printf(" this is inventory program  \n"
            " please choice the number of your option\n"
            " ************\n"
            " 1** for add product\n"
            " 2** for see the data of the store\n"
            " 3** for research product\n"
            " 4** for delete product\n"
            " 5** for modify any product\n"
            " 6** for store data\n"
            " 7** for delete all data\n"
            " 8** for exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            push();
            printf(" ******** \n");
        break;

        case 2:
            display(top);
            printf(" ******** \n");
            break;

        case 3:
            printf("please, Enter the code of the product \n");
            scanf("%d",&ch2);
            search(ch2);
            printf(" ******** \n");
        break;
        case 4:
            printf("please enter the code\n");
            scanf("%d",&ch3);
            pop(ch3);
            printf(" ******** \n");
            break;
        case 5:
            printf("please, Enter the code of the product \n");
            scanf("%d",&ch3);
            modify(ch3);
            printf(" ******** \n");
            break;
        case 6 :
            storedata();
            break;
        case 7:
            clear();
            break;
        case 8:
            fre=top;
                while(top != NULL){
                    top = top -> link;
                    free(fre);
                    fre = top;
                }
            exit(1);
            default :
                printf("\n please enter choice from 1 to 8 \n");


    }

}


    return (0);
}

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



void pop(int del){
     if(top==NULL){
        printf("the stack is empty\n");
    }
   else if(top->code==del){
    info *temp1;
    temp1=top;
   top=top->link;
    printf("the product of code = %d is deleted\n",del);
    free(temp1);
    }
    else{
        info *preptr, *currptr;
        preptr=top;
        currptr=top->link;
        while(currptr!=NULL && currptr->code!=del){
            preptr=currptr;
            currptr=currptr->link;
        }
        if(currptr!=NULL){
            preptr->link = currptr->link;
            free(currptr);
            printf("the product of code = %d is deleted\n",del);
        }
        else{
            printf("the code not exist\n");
        }
    }
}



void search(int a){
info *temp;
temp=top;
int counter=0 ;
while(temp!=NULL){
if(temp->code==a){
    printf("------The product is founded--------- \n");

    counter++;

    printf(" the code of product %d \n",temp->code);
    printf(" the Name of product %s \n",temp->name);
    printf(" the price of  %d \n",temp->price);
    printf(" the number of product %d \n",temp->number);
}
temp=temp->link;

}

if(counter==0){
    printf("------There is no result about this product ---------\n");
    }
}
void display(info *dis){
info *ptr2 ;
ptr2=dis;
if(ptr2==NULL){
    printf("The Store Is Empty \n");
}
else{
while (ptr2!=NULL)
{
    printf(" the code of product %d \n",ptr2->code);
    printf(" the Name of product %s \n",ptr2->name);
    printf(" the code of product %d \n",ptr2->price);
    printf(" the number of product %d \n",ptr2->number);
     printf(" ********************** \n");
ptr2=ptr2->link;

}
}
}

void modify(int a){
    info *temp;
    temp=top;
    int counter=0 ;
    if(temp==NULL){
    printf("The Store Is Empty \n");
}
    else{
    while(temp!=NULL){
        if(temp->code==a){
            printf("------The Item is founded--------- \n");

            counter++;

            printf(" the code of product %d \n",temp->code);
            printf(" the Name of product %s \n",temp->name);
            printf(" the price of  %d \n",temp->price);
            printf(" the number of product %d \n",temp->number);
            printf("\nif you want to add number to this product enter 1 \n "
                    "and if you want to remove number from this product enter 2 \n"
                    " if you want to change price for this product enter 3\n");
            int choice;
            int num;
            scanf("%d",&choice);
            if (choice==1){
                    printf("please enter the number that you want to add : ");
                    scanf("%d",&num);
                    temp->number+=num;
                    printf("the number has been added \n");
            }
            else if(choice == 2){
                    printf("please enter the number that you want to decrease : ");
                    scanf("%d",&num);
                    temp->number-=num;
                    printf("the number has been decreased \n");

            }
            else if(choice == 3){
                printf("please enter the new price \n");
                scanf("%d",&temp->price);
                puts("the price has been changed \n");
            }
            else{
                puts(" wrong choice ");
            }
}
        temp=temp->link;
}
    if(counter==0){
    printf("------There is no result about this product ----------\n");
    }
    }
}
void storedata(){
             if((fptr=fopen("dada.txt","wb"))==NULL){
        printf("can not open the file\n");
        exit(2);
        }
        ptr=top;
   while (ptr!=NULL){
      item.code=ptr->code;
    strcpy(item.name,ptr->name);
    item.price=ptr->price;
    item.number=ptr->number;

     fwrite(&item,sizeof(item),1,fptr);
     ptr=ptr->link;
}
 fclose(fptr);
}
void read(){
    if((fptr=fopen("dada.txt","rb"))==NULL){
        printf("can not open the file\n");
        exit(3);}
        while(fread(&item,sizeof(item),1,fptr)){


                 ptr=( info *) malloc(sizeof(info));

    if(top==NULL)
    {
                top=ptr ;
                ptr->link=NULL;

    }
    else {
                ptr->link=top;
                top=ptr;}


    top->code=item.code;
    strcpy(top->name,item.name);
    top->price=item.price;
    top->number=item.number;


        }
        fclose(fptr);
}
void clear(){
      fptr=fopen("dada.txt","wb");
      fclose(fptr);

}
