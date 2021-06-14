void search(int a);
void modify(int a);


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
                    "and if you want to remove number from this product enter 2 \n");
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
