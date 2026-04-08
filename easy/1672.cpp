class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        int m=accounts.size();
        int n=accounts[0].size();
        for(int i=0;i<m;i++){
            int w=0;
            for(int j=0;j<n;j++){
                w+=accounts[i][j];
            }
            maxi=max(maxi,w);
        }
        return maxi;
    }
};