class Solution {
public:
    int maxArea(vector<int>& height) {
        //contribution tech
        int n=height.size();
        vector <pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({height[i],i});
        }
        sort(arr.begin(),arr.end());
        int currmin=arr[n-1].second, currmax=arr[n-1].second;
        int ans=INT_MIN;
        for(int i=n-2;i>=0;i--){
            int maxi=max(abs(arr[i].second-currmin),abs(arr[i].second-currmax));
            ans=max(ans,arr[i].first*maxi);
            currmin=min(currmin,arr[i].second);
            currmax=max(currmax,arr[i].second);
        }
        return ans;
        
    }
};