#include<stdio.h>
#include<stdlib.h>
struct link
{
    int data;
    struct link *next;
};

void insertend(struct link **head,int v){
    struct link *nlink=(struct link*)malloc(sizeof(struct link));
    nlink->data=v;
    nlink->next=NULL;

    if (*head==NULL){
        *head=nlink;
        return;
    }
    struct link *t=*head;
    while (t->next!=NULL)
    {
        t=t->next; 
    }
    t->next=nlink;   
}

void insertbegin(struct link **head,int v){
    struct link *nlink=(struct link*)malloc(sizeof(struct link));
    nlink->data=v;
    nlink->next=*head;
    *head=nlink;
}

void insertpos(struct link **head,int v,int pos){
    struct link *nlink=(struct link*)malloc(sizeof(struct link));
    nlink->data=v;
    if(pos==1){
        nlink->next=*head;
        *head=nlink;
        return;
    }else{
        struct link *t=*head;
        for (int i = 1; i < pos-1; i++)
        {
            t=t->next;
        }
        nlink->next=t->next;
        t->next=nlink;
    }
}

void display(struct link *head){
    struct link *temp=head;
     printf("\n\t--DISPLAY--\n");
       
    while (temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    
}

void deleteend(struct link **head){
    if (*head==NULL){
        printf("List is empty\n");
        return;
    }
    if ((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    } 
    struct link *t=*head;
    while (t->next->next!=NULL)
    {
        t=t->next;
    }
    free(t->next);
    t->next=NULL;
}

void deletebeging(struct link **head){
    if (*head==NULL){
        printf("List is empty\n");
        return;
    }
    struct link *temp=*head;
    *head=(*head)->next;
    free(temp);
}

void deletepos(struct link **head,int pos){
    if (*head==NULL){
        printf("List is empty\n");
        return;
    }
    if (pos==1){
        struct link *temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    struct link *t=*head;
    for (int i = 1; i < pos-1; i++)
    {
        t=t->next;
    }
    struct link *temp=t->next;
    t->next=temp->next;
    free(temp);
}

void freeall(struct link **head){
    struct link *temp=*head;
    while (temp!=NULL)
    {
        struct link *next=temp->next;
        free(temp);
        temp=next;
    }
    *head=NULL;
}

int count(struct link *head){
    int c=0;
    struct link *temp=head;
    while (temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

int search(struct link *head,int v){
    int pos=1;
    struct link *temp=head;
    while (temp!=NULL)
    {
        if (temp->data==v){
            return pos;
        }
        temp=temp->next;
        pos++;
    }
    if(temp==NULL){
        printf("Value not found\n");
    }
    return -1;
}

void reverse(struct link **head){
    struct link *prev=NULL;
    struct link *current=*head;
    struct link *next=NULL;
    while (current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
    display(*head);
}
void sort(struct link **head){
    if (*head==NULL){
        printf("List is empty\n");
        return;
    }
    struct link *i,*j;
    for (i = *head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
        
    }
    display(*head);
}
int size(struct link *head){
    int c=0;
    struct link *temp=head;
    while (temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}
/* void choice(struct link **head,int ch){
    int v;   
}
 */
int main(){
    int n,v,ch;
    printf("Enter the limit ");
    scanf("%d",&n);
    struct link *head=NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d value ",i+1);
        scanf("%d",&v);
        insertend(&head,v);
    }
    display(head);

    while(1){
    printf("\nEnter 1 to insert at beginning ");
    printf("\nEnter 2 to insert at end ");
    printf("\nEnter 3 to insert at position ");
    printf("\nEnter 4 to display ");
    printf("\nEnter 5 to delete at end ");
    printf("\nEnter 6 to delete at beginning ");
    printf("\nEnter 7 to delete at position ");
    printf("\nEnter 8 to search ");
    printf("\nEnter 9 to reverse ");
    printf("\nEnter 10 to sort ");
    printf("\nEnter 11 to exit ");
    scanf("%d",&ch);
    //choice(&head,ch);
    
     
    switch (ch)
    {
    case 1:
        printf("Enter value to insert at beginning ");
        scanf("%d",&v);
        insertbegin(&head,v);
        printf("Inserted at beginning\n");
        display(head);
        break;
    case 2:
        printf("Enter value to insert at end ");
        scanf("%d",&v);
        insertend(&head,v);
        printf("Inserted at end\n");
        display(head);
        break;
    case 3:
        printf("Enter value to insert at position ");
        scanf("%d",&v);
        int pos;
        printf("Enter position to insert ");
        scanf("%d",&pos);
        if (pos>size(head)+1) {
            printf("Invalid position\n");
            break;
        }
        insertpos(&head,v,pos);
        printf("Inserted at position %d\n",pos);
        display(head);
        break;
    case 4:
        display(head);
        break;
        //exit(0);
    case 5:
        deleteend(&head);
        printf("Deleted at end\n");
        display(head);
        break;
    case 6:
        deletebeging(&head);
        printf("Deleted at beginning\n");
        display(head);
        break;
    case 7:
        printf("Enter position to delete ");
        scanf("%d",&pos);
        if (pos>size(head)) {
            printf("Invalid position\n");
            break;
        }
        deletepos(&head,pos);
        printf("Deleted at position %d\n",pos);
        display(head);
        break;
    case 8:
        printf("Enter value to search ");
        scanf("%d",&v);
        int res=search(head,v);
        if (res!=-1){
            printf("Value found at position %d\n",res);
        }
        break;
    case 9:
        reverse(&head);
        break; 
    case 10:
        sort(&head);
        display(head);
        break;
    case 11:
        printf("Size of the list: %d\n", size(head));
        freeall(&head);
        printf("All memory freed\n");
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}
    display(head); 
    
    
   
    return 0;   
}