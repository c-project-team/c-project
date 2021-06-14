#include<stdio.h>

void main (void){
 typedef struct   {
int code ;
char name[25];
int price ;
int number;
struct  info *link ;

}info;
info *ptr,*top;
info item;
 int ans;
 top=NULL;
 FILE *fptr;

    if((fptr=fopen("dada.txt","wb"))==NULL){
        printf("can not open the file\n");
        exit(1);}
     do{
            printf("code   :\n");
             scanf("%d",&item.code);
              printf("name   :\n");
              scanf("%s",item.name);
               printf("salary   :\n");
               scanf("%d",&item.price);
               printf("number  :\n");
               scanf("%d",&item.number);
               fwrite(&item,sizeof(item),1,fptr);
               printf("another agent?");
              scanf("%d",&ans);
     } while(ans==1);
     fclose(fptr);


      if((fptr=fopen("dada.txt","rb"))==NULL){
        printf("can not open the file\n");
        exit(2);}
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


  ptr=top;
   while (ptr!=NULL)
{
    printf(" the code of product %d \n",ptr->code);
    printf(" the Name of product %s \n",ptr->name);
    printf(" the price of product %d \n",ptr->price);
    printf(" the number of product %d \n",ptr->number);
ptr=ptr->link;

}

 printf("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n");


return(0);

}
