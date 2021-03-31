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

ins(List * lst, int data) {
Node* new = (Node*)malloc(sizeof(Node));
new ->data = data;
new ->next = NULL;

 Node* current = lst->head;
 
 if (current == NULL)   {
 lst->head = new;
 lst->size++;
 } else{
     while(current->next != NULL)
         current = current->next;
     current->next = new;  
     lst->size++;     
 }
// free(new->next);
}

printNode(Node*n){
    if(n == NULL){
    printf("[]");
    return;
   }
    printf("[%d] ", n->data); 
   
}

printList(List* lst) {
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

Node * tmp = from->head;
while(tmp ->next != NULL) {
ins(to, tmp->data);
tmp = tmp->next;
}

ins(to, tmp->data);
//free(tmp->next);
}
int main()
{

    List* from = (List*) malloc(sizeof(List));
    List* to = (List*) malloc(sizeof(List));
    init(from);
    init(to);
    printList(from);
    ins(from,1);
    ins(from, 2);
    ins(from,1);
    ins(from,4);
    ins(from,5);
    copy(from, to);
    printList(to);
    printList(from);

//    free(from);
    

//    free(to);

return 0;
}


