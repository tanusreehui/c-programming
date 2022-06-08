#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node{
    int data;
    struct node *next;
}node;
int main()
{
    node *head=NULL,*ptr=NULL,*last;
    int choice,number;
    srand(time(NULL));

    do{
        printf("\n\t\t1. Add Node");
        printf("\n\t\t2. Create random Nodes");
        printf("\n\t\t3. Display Nodes");
        printf("\n\t\t9. Exit");
        printf("\n\t\t\t\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nAdding node ......");

                //Dynamically memory allocation
                ptr=(node*)malloc(sizeof(node));
                if(ptr==NULL){
                    printf("\nUnable to allocate memory");
                    exit(0);
                }
                // dynamic memory is allocated
                ptr->next=NULL;
                printf("\nEnter a number for node: ");
                scanf("%d",&number);
                ptr->data=number;
                //checking head for value
                if(head==NULL){
                    //this is first node
                    head=ptr;
                    last=ptr;
                }else{
                    last->next=ptr;
                    last=ptr;
                }
                break;
            case 2:
                printf("\nEnter number of nodes: ");
                scanf("%d",&number);
                while(number>0){
                    number--;
                    ptr=(node*)malloc(sizeof(node));
                    if(ptr==NULL){
                        printf("\nUnable to allocate memory");
                        break;
                    }
                    ptr->next=NULL;
                    ptr->data=rand()%100;
                    //checking head for value
                    if(head==NULL){
                        //this is first node
                        head=ptr;
                        last=ptr;
                    }else{
                        last->next=ptr;
                        last=ptr;
                    }

                }
                break;
            case 3:
                //display node
                ptr=head;
                printf("\n Nodes are .........\n");
                while(ptr!=NULL){
                    printf("%d, ",ptr->data);
                    ptr=ptr->next;
                }
                break;
        }
    }while(choice!=9);
    return 0;
}

