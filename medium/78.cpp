class Solution {
public:
    vector <vector<int>> ans;
    void rec(vector <int> &temp, vector <int> &nums, int i){
        if(i==nums.size()) {
            ans.push_back(temp);
            return;
        }
        //explore
        //take
        // ans.push_back(temp);
        temp.push_back(nums[i]);
        rec(temp,nums,i+1);
        //or skip
        temp.pop_back();
        rec(temp,nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <int> a={};
        rec(a, nums,0);
        return ans;
        
    }
};