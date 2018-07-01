
#include <stdio.h>

void swap(int *a, int *b){
    
    int t = *a;
    *a = *b;
    *b = t;
}

void quicksort(int left, int right, int *data){
    
    int pivot = left;
    int j = pivot;
    int i = left + 1;
    
    if(left < right){
        for(; i<= right; i++){
            if(data[i] < pivot[i]){
                j++;
                swap(&data[i], &data[j]);
            }
        }
        swap(&data[left], &data[j]);
        pivot = j;
        
        quicksort(left, pivot-1, data);
        quicksort(pivot+1, right, data);
    }
}

int main(void){
    
    int i;
    int arr[5] = {4,2,3,1,5};
    quicksort(0, 4, arr);
    
    for(i=0; i<5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}






















