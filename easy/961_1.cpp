class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size(), ans=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n+1;i++){
            if(nums[i]==nums[i+1]){ ans=nums[i]; break;}
        }  
        return ans;
    }
};