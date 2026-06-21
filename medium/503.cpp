class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // duplicate the array
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }

        stack<int> st;
        vector<int> ans(n,-1);

        for(int i=2*n-1;i>=0;i--){

            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }

            // Only store answers for original array
            if(i<n){
                if(!st.empty()){
                    ans[i]=st.top();
                }
            }

            st.push(nums[i]);
        }

        return ans;
    }
};