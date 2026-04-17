class Solution {
public:
    long long reverse(int x){
        long long ans=0;
        while(x!=0){
            ans = ans*10 + x%10;
            x/=10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int> mp;
        int ans = INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[reverse(nums[i])]=i;
        }

        return ans==INT_MAX ? -1 : ans;
    }
};