#include <stdio.h>
#include <stdlib.h>

void fillRandom(int * arr, int len1, int border) {
    for (int i = 0; i  < len1; ++i) {
        *(arr + i ) = rand() % border;
        }
    }


void printarr(int *arr, int r) {
    for (int i = 0 ; i < r; i ++) {
        printf("%3d ", *(arr + i) );
}
    printf("\n");
}

void bucketsort(int * arr, int len) { const int max = len;
const int b = 10;
int buckets[b][max +1];
for (int i =0; i < b; ++i) {
buckets[i][max] = 0;
}
int tmp[max];
for (int i = 0; i < max; i++)
tmp[i] = arr[i];
for (int i = 0; i  < max; ++i) 
for (int digit = 1; digit < 1000000000; digit *= 10) {
    for (int i = 0; i < max; ++i) { 
    int d = (arr[i]/digit) % b;
    if(arr[i] % 2 == 0)
    buckets[d][buckets[d][max]++] = arr[i]; 
    }
        
    int idx = 0;
    for (int i = 0; i < b; ++i) { 
    for (int j = 0; j < buckets[i][max]; ++j) { 
    if(arr[idx] % 2 == 0) {
            arr[idx++] =buckets[i][j];
            }
            else {
            do {
            idx++;
            } while(arr[idx] % 2 != 0);
           arr[idx++] =buckets[i][j]; 
            }
            }
  buckets[i][max] = 0;
  }
  }  
 
}

int main()
{
int len; 
scanf("%d", &len);
int arr[len];
fillRandom(arr, len,100);
printarr(arr,len);
bucketsort( arr, len);
printarr(arr,len);
 
    return 0;
}



