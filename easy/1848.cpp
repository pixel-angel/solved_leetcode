class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int leftidx=-1,rightidx=-1;
        for(int i=start;i>=0;i--){
            if(nums[i]==target){
                leftidx=i;
                break;
            }
        }
        for(int i=start+1;i<nums.size();i++){
            if(nums[i]==target){
                rightidx=i;
                break;
            }
        }
        if(leftidx==-1) return rightidx-start;
        else if(rightidx==-1) return start-leftidx;
        else return min(rightidx-start,start-leftidx);
    }
};