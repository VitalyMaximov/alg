#include <stdio.h>
#include <stdlib.h>


void swap (int * a, int *b) {
    int temp;
    temp = *a;
    *a = *b; 
    *b = temp;
}


void fillRandom(int * arr, int len1, int border) {
    for (int i = 0; i  < len1; ++i) {
        *(arr + i )= rand() % border;
        }
    }


void printarr(int *arr, int r) {
    for (int i = 0 ; i < r; i ++) {
        printf("%3d ", *(arr + i) );
}
    printf("\n");
}

void sortinsert (int *arr, int n) {
int temp, pos; 
for (int i = 1; i < n; i++) {
temp = arr[i]; pos = i-1;
while(pos >= 0 && arr[pos] > temp) {
   arr[pos +1] = arr[pos];
   pos--;  
}
arr[pos+1] = temp;
}
}

void qs (int* arr, int first, int last) {
       
    int i = first, j = last, x = arr[(first + last)/2];
    do {// разбиение Хaора        по опорному эл Smal & Big - x
    while (arr[i] < x) i++;
    while (arr[j] > x) j--;
    if (i <= j) {
        swap (&arr[i], &arr[j]);
        i++;
        j--;
    }
    } while (i <= j);
    if (i < last) qs (arr, i , last);
    if (first < j)  qs (arr, first, j);
}

void quicksort(int *arr, int first, int last) {
    if (last-first < 10) { // last +1 <= 10             поправки              Всего доброго! ! ! 
         sortinsert(arr,  last+1/*sizeof(arr)*/);   //поправки
    }
    else {
       int b, s, e;
       b = first; s = (first + last)/2; 
       e = last;
      
       if ( s < b && b < e) {
       swap(&b, &s) ; 
       qs (arr, b, e) ;
       }
       else if (b < e && e < s) {
       swap (&e, &s); 
       qs (arr, b, e) ;
       }

      else if (b <= s && s <= e) 
      qs (arr, b, e) ;
      
   } 
} 


int main()
{
int r;
   printf("r \n");
   scanf("%i", &r);
   const int len = r;
   int arr[len];
   fillRandom(arr, r, 15);
   printarr(arr, r);
   quicksort (arr, 0, r-1);
   printarr(arr, r);
   
    return 0;
}
