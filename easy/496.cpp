class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map <int,int> ans;
        
        stack <int> st;
        
        for(int i=n-1;i>=0;i--){
            while(true){
                if(st.empty()){
                    ans[nums2[i]]=-1; break;
                }
                else if(st.top()>nums2[i]){
                    ans[nums2[i]]=st.top(); 
                    break;
                }
                else st.pop();
            }
            st.push(nums2[i]);
        }
        vector <int> f;
        for(auto i:nums1){
            f.push_back(ans[i]);
        }
        
        return f;        
    }
};