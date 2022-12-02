#include <stdio.h>

int linear_search(int *arr, int len, int n){
    for(int i=0; i<len; i++){
        if(arr[i]==n) return i;
    }
    return -1;
}

int main(){
    int nums[] = {2,5,6,4,8,9,7};
    int len = sizeof(nums)/sizeof(nums[0]);
    int key=6;
    int soln = linear_search(nums, len, key);

    if(soln != -1) printf("Value %d was found at index:- \t%d\n", key, soln);
    else printf("No value: %d\n",key);

}
