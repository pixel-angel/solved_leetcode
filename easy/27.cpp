class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                nums[i]=51; k--;
            }
        }
        sort(nums.begin(),nums.end());
        return k;        
    }
};