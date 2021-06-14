
read();
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
