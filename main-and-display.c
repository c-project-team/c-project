#include<stdio.h>
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
int main() {

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
            exit(1);
            default :
                printf("\n please enter choice from 1 to 8 \n");


    }

}


    return (0);
}
