#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node *next; 
} Node;

typedef struct {
Node* head;
int size;
}List;

void init(List* lst){
lst->head = NULL;
lst->size = 0;
}

void ins(List * lst, int data) {
Node* new = (Node*)malloc(sizeof(Node)); // we have dinamic memory
new ->data = data;
new ->next = NULL;

 Node* current = lst->head;
 
 if (current == NULL)   {
 lst->head = new;
 lst->size++;
 } else{
     while(current->next != NULL) //  we reach the end of the list
         current = current->next;
     current->next = new;  
     lst->size++;     
 }
}

void printNode(Node*n){
    if(n == NULL){
    printf("[]");
    return;
   }
    printf("[%d] ", n->data); 
   
}

void printList(List* lst) {
Node* current = lst->head;

    if(current == NULL){
    printNode(current);

    }else{
    do{
    printNode(current);
    current = current->next ;
    }while(current != NULL);
    }
     printf(" Size: %d\n", lst->size);
}

void copy(List* from, List* to) {
Node * tmp = from->head; //pointer
while(tmp ->next != NULL) {
ins(to, tmp->data); // defining the elements of the "to" list
tmp = tmp->next;
}
ins(to, tmp->data);
}

Node* clear (List* lst) {
Node* current = lst->head;
 
 if (current == NULL)   
return NULL;

    while(current -> next != NULL) //  we reach the end of the list
         current = current->next;
    free( current -> next );  // and cleaning memory
    lst->size--;     
}

 

int main()
{

    List* from = (List*) malloc(sizeof(List));
    List* to = (List*) malloc(sizeof(List));
    init(from);
    init(to);
    printList(from);
    ins(from,1);// defining the elements of the "from" list
    ins(from, 2);
    ins(from,1);
    ins(from,4);
    ins(from,5);
    copy(from, to);
    printList(to);
    printList(from);
    while(from->size >= 0){
    clear(from);
    }
    while(to->size >= 0){
    clear(to);
    }

    free(from);
    free(to);

return 0;
}
