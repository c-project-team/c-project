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
