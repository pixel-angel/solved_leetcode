class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        //normal prefix sum?
        int ans=0;
        for(int i=1;i<gain.size();i++){
            gain[i]+=gain[i-1];
        }
        ans=max(ans,*max_element(gain.begin(),gain.end()));
        return ans;        
    }
};