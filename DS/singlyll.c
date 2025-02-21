#include <stdio.h>
#include <stdlib.h>
struct ND{
    int info;
    struct ND* next;
};//inserting an element in the beginning.
struct ND* inbeg(struct ND* first,int X){
    //allocate node
    struct ND* newnd;
    newnd=(struct ND*)malloc(sizeof(struct ND));
    if (newnd==NULL){
        printf("Some Error!! \n");
    }
    //assign value
    newnd->info=X;
    newnd->next=NULL;
    if (first==NULL){
            first=newnd;
    }
    else{
        newnd->next=first;
        first=newnd;
    }
};//deleting an element from the front.
struct ND* delbeg(struct ND* first){
    if (first==NULL){
        printf("UNDERFLOW\n");
        return first;
    }
    struct ND* temp=first;
    first=first->next;
    free(temp);
    return first;
};//inserting an element in the end.
struct ND* inend(struct ND* first,int X){
    //allocate node
    struct ND* newnd1,*curr;
    newnd1=(struct ND*)malloc(sizeof(struct ND));
    newnd1->info=X;
    newnd1->next=NULL;
    if (first==NULL){
            return newnd1;
    }
    for(curr=first;curr->next!=NULL;curr=curr->next);
    curr->next=newnd1;
    //assign value
    return first;
};//deleting an element from the end,
struct ND *delast(struct ND *first){
    struct ND *prev;
    if(first==NULL){
        printf("UNDERFLOW\n");
        return first;
    }
    else if(first->next==NULL){
        struct ND *temp=first;
        first=NULL;
        free(temp);
        return first;
    }
    else{
        struct ND *temp=first;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
        return first;
    }
};//deleting the element before specified position
struct ND* delposbefore(struct ND *first,int y){
    int i;
    int n=y;
    struct ND *temp=first;
    struct ND *prev;
    if(temp==NULL){
        printf("LIST IS EMPTY!! Kindly add elements..\n");
        return first;
    }
    for(i=0;i<n-1;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return first;
}
struct ND* delposafter(struct ND *first,int y){
    int i;
    int n=y;
    struct ND *temp=first;
    struct ND *prev;
    if(temp==NULL){
        printf("LIST IS EMPTY!! Kindly add elements..\n");
        return first;
    }
    for(i=0;i<n+1;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return first;
}
void disp(struct ND* first){
    if (first==NULL){
        printf("List is empty!!");
    }
    else{
        struct ND*curr;
        curr=first;
        while(curr!=NULL){
            printf("%d \n",curr->info);
            curr=curr->next;
        }
    }
}

int main()
{
    printf("En. No. 210410107004\nName:Hetvi Patel\n");
    struct ND* first=NULL;
   printf("1.Insert a node at the front of the linked list.\n2.Insert a node at the end of the linked list.\n");
   printf("3.Delete a first node of the linked list.\n4.Delete a node before specified position.\n");
   printf("5.Delete a node after specified position.\n6.Display the list.\n"); 
   int choice=0,value,position;
   while(1){
    printf("Enter your choice:");
    scanf("%d",&choice);
    if (choice==7){break;}
    else{
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to insert(beg):");
            scanf("%d",&value);
            first=inbeg(first,value);
            break;
        case 2:
            printf("Enter the value you want to insert(last):");
            scanf("%d",&value);
            first=inend(first,value);
            break;
        case 3:
             first=delbeg(first);
            break;
        case 4:
            printf("Enter the position whose preceding element is to be deleted:");
            scanf("%d",&position);
            first=delposbefore(first,position);
            break;
        case 5:
            printf("Enter the position whose succeeding element is to be deleted:");
            scanf("%d",&position);
            first=delposafter(first,position);
            break;
        case 6:
            disp(first);
            break;
        default:
            printf("Invalid choice!!\n");
            break;
        }
    /* Insert a node at the front of list */
    }
    }
    return 0;
}
