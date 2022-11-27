#include <stdio.h>
#include <stdbool.h>

void swap(int *arr, int len){
    for(int i =0;i<len-1;i++){
        int t=arr[i];
        if(t>arr[i+1]){
            arr[i]=arr[i+1];
            arr[i+1]=t;
        }
        printf("%d\t|\t",i);display(arr, len);

    }
}

bool unsorted(int *arr, int len){
    for(int i=0;i<len-1; i++){
        if(arr[i]>arr[i+1]) return true;
    }
    return false;
}

void display(int *arr, int len){
    for(int n=0; n<len; n++) printf("%d ",arr[n]);
    printf("\n");
    
}

void main(){
    int nums[]={385,300,371,915, 451,698,567,754};
    int len=sizeof(nums)/sizeof(nums[0]);
    printf("Initial:-\t");
    display(nums, len);
  
    while(unsorted(nums, len)) swap(nums, len);
}


