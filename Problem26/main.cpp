#include "stdio.h"

/* C version
 * remove from last to begin
 * */
int removeDuplicatesByC1(int *nums,int numsSize){
    int i=numsSize-1,lastIndex=numsSize-1;
    while(i>0){
        if(nums[i]==nums[i-1]){
            //move the numbers behind ith number for one step
            int j=i+1;
            while(j<=lastIndex){
                nums[j-1]=nums[j];
                j++;
            }
            lastIndex--;
            numsSize--;
        }
        i--;
    }
    return numsSize;
}
int removeDuplicatesByC2(int *nums,int numsSize){
    if(numsSize==0) return 0;
    int i=1,newi=1;
    while(i<numsSize){
        if(nums[i]!=nums[i-1]){
            nums[newi]=nums[i];
            newi++;
        }
        i++;
    }
    return newi;
}
int main() {
    int nums[]={1,1,2,2,2,3,3,5,6};
    int res=removeDuplicatesByC1(nums,9);
    printf("%d\n",res);
    for(int i=0;i<res;i++){
        printf("%d\n",nums[i]);
    }
    return 0;
}