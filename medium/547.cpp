class Solution {
public:
    vector <int> vis;
    int n;
    void dfs(int i,vector<vector<int>>& isConnected){
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(isConnected[i-1][j]==1 && !vis[j+1]){
                dfs(j+1,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //to tell number of components;
        n=isConnected.size();
        vis.assign(n+1,0);
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected);
            }
        }
        return ans;

        
    }
};