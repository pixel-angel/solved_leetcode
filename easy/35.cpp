class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) e=mid-1;
            else s=mid+1;
        }
        if(target<nums[mid]) return mid;
        return mid+1;
    }
};