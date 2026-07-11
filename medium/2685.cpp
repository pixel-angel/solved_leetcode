class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //make adjacenecy list. 
        vector <vector<int>> adjlist(n);
        for(auto &v : edges){
            adjlist[v[0]].push_back(v[1]);
            adjlist[v[1]].push_back(v[0]);
        }
        int ans=0;
        vector <int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                //do dfs for i and ans++;
                stack<int> st;
                st.push(i);
                vis[i]=1;
                int nodes=1,edges=0;
                while(!st.empty()){
                    int curr=st.top();
                    st.pop();
                    edges += adjlist[curr].size();
                    for(auto i: adjlist[curr]){
                        if(!vis[i]){
                            st.push(i);
                            nodes++;
                            // edges++;
                            vis[i]=1;
                        }
                    }
                }
                edges/=2;
                if(edges==(nodes*(nodes-1)/2)) ans++;
                
            }
        }
        return ans;
    }
};