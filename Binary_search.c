#include <stdio.h>

void binary_search(int *arr, int len, int n){
    int low=0, high=len-1;
    int mid = (low+high)/2;
    while(low<=high){
        if(n < arr[mid]){
            high=mid-1;     
        }
        else if(arr[mid] == n){
            printf("Value %d is at location %d\n", n, mid);
            break;
        }
        else{
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    if(low>high){
        printf("Value %d not found\n", n);
    }
}

void main(){
    int nums[] = {1,2,3,4,5,6,7,8,9};
    int len= sizeof(nums)/sizeof(nums[0]);
    for(int i=1; i<11; i++){
        binary_search(nums, len, i);
    }
}
