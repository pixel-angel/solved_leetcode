class Solution {
public:
    int findpivot(vector<int>& nums) {

        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {

            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return s;
    }

    int search(vector<int>& nums, int target) {
        // phele pivot dhundna h
        // fir binary search usee

        int n = nums.size();

        if(nums[n-1] == target) return n-1;

        // pivot using bs
        int pivot = findpivot(nums);

        int s, e;

        if(target > nums[n-1]){
            s = 0;
            e = pivot - 1;
        }
        else{
            s = pivot;
            e = n - 1;
        }

        int ans = -1;

        while(s <= e){

            int mid = s + (e - s) / 2;

            if(nums[mid] > target){
                e = mid - 1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                ans = mid;
                break;
            }
        }

        return ans;
    }
};