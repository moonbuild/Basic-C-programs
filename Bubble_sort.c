#include <stdio.h>

void display(int *arr, int len){
    for(int n=0; n<len; n++) printf("%d ",arr[n]);
    printf("\n");
    
}

void bubbleSort(int *arr, int len){
    int i=0,j=0;
    display(arr, len);
    while(i<len-1){
        while(j<len-i-1){
            if(arr[j]>arr[j+1]){
                int val = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = val;
            }
            j++;
            display(arr, len);
        }
        i++;
    }
}

void main(){
    int nums[]={385,300,371,915, 451,698,567,754};
    int len=sizeof(nums)/sizeof(nums[0]);

    bubbleSort(nums, len);
}


