#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define SZ 50
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;
boolean sort(T* str) {

int buf[strlen(str)], idx = 0;
unsigned int init = 0;
while(strlen(str)>init)
    buf[init++] = -1;
int flag = 0;

  for(unsigned int i = 0; i < strlen(str); i++) {
  
  if (str[i] == ')' || str[i] == '}' || str[i] == ']')  { 
      flag = 1;
  char c;
  int j = i;                    
  if(str[i] == ')') c = '(';
    if(str[i] == '}') c = '{';
      if(str[i] == ']') c = '[';
  while(str[j] != c && j != buf[idx] && j >= 0){ 
      j--;
  }
  if (str[j] == c)
      buf[idx++] = j;
  else
      return false;
  }
  }
 if (flag == 0) 
     return false;
  return true;
  } 
//------------------------------------------------------------

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
if(lst == NULL) {
printf ("\nwe have list is NULL\n");
return ;
}
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

void  clear (List* lst) {
Node* current = lst->head;
 
 if (current == NULL)   
     return ;

    while(current -> next != NULL) //  we reach the end of the list
         current = current->next;
    free( current -> next );  // and cleaning memory
    lst->size--;     
}
//3--------------------------------------------------------------

int Sort(List* from) {

Node* current = from->head;
if (current == NULL)   
     return 0;

  while(current->next != NULL){
  if(!(current->data <= current->next->data))
return 0;
         current = current->next;
  } 
  return 1; 
 }
 
 int Sort2(List* from) {

if (from->head == NULL)   
     return 0 ;

 while(from->head->next != NULL) {
    if(!(from->head->data >= from->head->next->data)) {
return 0;
}
from->head = from->head->next;
}
return 1;
 }

boolean isSort(List* from) {
 if(from->head == NULL){
return false;
}
 return (Sort(from) ?  true : Sort2(from) ?  true :  false);
}

int main()
{
//1----------------------------------------------------------
printf("Bracket sequence: ");
    T m[SZ];
   unsigned int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < SZ  ) {
        m[i] = c;
        i++;
    }
    for (i = 0; i < strlen(m); ++i ) {
        printf("%c", m[i]);
    }
   if(sort(m))
       printf(" - true\n");
   else
       printf(" - false\n");
//2-------------------------------------------------------------------
printf("This is list edit and copy: ");
    List* from = (List*) malloc(sizeof(List));
    List* to = (List*) malloc(sizeof(List));
    init(from);
    init(to);
    printList(from);
    ins(from,1);// defining the elements of the "from" list
    ins(from, 2);
    ins(NULL, 2);
    ins(from,1);
    ins(from,4);
    ins(from,5);
    copy(from, to);
    printList(to);
    printList(from);
    while(from->size > 0){
    clear(from);
    }
    while(to->size > 0){
    clear(to);
    }

    free(from);
    free(to);
 //3---------------------------------------------------------------
 
    from = (List*) malloc(sizeof(List));
    int data;
        init(from);
        printList(from);
        printf ("List. Enter 99 for exit:");
        while(data != 99){
            scanf("%d" , &data);
            if (data == 99)
                break;
        ins(from, data);
        }
      printList(from);
      if(isSort(from))
          printf(" - sotr\n");
      else
          printf(" - no sort\n");

      while(from -> size > 0) {
          clear(from);
      }
      free(from);
 
    return 0;
}





