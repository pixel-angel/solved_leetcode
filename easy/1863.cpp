class Solution {
public:
    int rec(vector <int> & nums, int i, int xr){
        if(i==nums.size()) return xr;
        return (rec(nums,i+1,xr)+rec(nums,i+1,xr^nums[i]));
    }
    int subsetXORSum(vector<int>& nums) {
        return rec(nums,0,0);        
    }
};