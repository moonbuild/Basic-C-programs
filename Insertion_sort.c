#include <stdio.h>


void display(int *arr, int len){
    for(int n=0; n<len; n++) printf("%d ",arr[n]);
    printf("\n");
    
}

void main(){
    int nums[]={385,300,371,915, 451,698,567,754};
    int len=sizeof(nums)/sizeof(nums[0]);

    for(int i=0; i<len; i++){
        int now=nums[i];
        int j=i;
        while(now>0, now<nums[j-1]){
            nums[j]=nums[j-1];
            j--;
            display(nums,len);
        }
        nums[j]=now;
        
        
    }
    display(nums, len);
}
