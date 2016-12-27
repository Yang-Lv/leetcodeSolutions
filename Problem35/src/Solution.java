/**
 * Created by lvyang on 12/27/16.
 */
public class Solution {
    public int searchInsert(int[] nums,int target){
        int len=nums.length;
        if(len==0){
            return 0;
        }
        int left=0;
        int right=len-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    }
    public static void main(String[] args){
        int[] nums={1,3,5,7,9,11};
        System.out.print(new Solution().searchInsert(nums,12));
    }
}
