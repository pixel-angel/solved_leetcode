class Solution {
public:
    struct monodq{
        deque <int> dq;
        void insert(int x){
            while(!dq.empty() && dq.back()<x) dq.pop_back();
            dq.push_back(x);
        }
        void erase(int x){
            if(dq.front()==x) dq.pop_front();
        }
        int getmax(){ return dq.front();}
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        monodq md;
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            md.insert(nums[i]);
            if((i-k)>=0) md.erase(nums[i-k]);
            if(i>=(k-1)) ans.push_back(md.getmax());
        }
        return ans;        
    }
};