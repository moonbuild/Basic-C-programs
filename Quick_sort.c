#include <stdio.h>

void display(int *arr, int len){
    for(int n=0; n<len; n++) printf("%d ",arr[n]);
    printf("\n");
    
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high){
    // int nums[]={385,300,371,915, 451,698,567,754};
    int pivot=arr[low];
    int i=low, j=high;
    //left-> find an element greater than pivot;
    //right-> find an element less (or equal) than pivot;
    while(i<j){
        while(arr[i]<=pivot) i++; //i=3
        while(arr[j]>pivot) j--; //j=2
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
     
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high){
    if(low<high){
        int len=high+1;
        // display(arr, len);
        int j = partition(arr, low, high);
        quickSort(arr, low, j);
        // display(arr, len);
        quickSort(arr, j+1, high);
        // display(arr, len);
    }
}

void main(){
    int nums[]={385,300,371,915, 451,698,567,754};
    int len=sizeof(nums)/sizeof(nums[0]);
    quickSort(nums, 0, 7);
}
