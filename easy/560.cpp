class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        map <int,int> mp;
        mp[0]++;
        int ans=0;
        for(auto i:nums){
            ans+=mp[i-k];
            mp[i]++;
        }
        return ans;
        
    }
};