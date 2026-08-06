class Solution {
public:
    vector<vector<int>> g;
    vector <int> indeg;
    vector<int> topo;

    void kahn(int n){
        queue <int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            topo.push_back(cur);
            for(auto v:g[cur]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }
    }

    vector<int> findOrder(int num, vector<vector<int>>& prereq) {
        //using kahns algo/bfs
        g.assign(num,{});
        indeg.assign(num,0);
        for(auto v:prereq){
            g[v[0]].push_back(v[1]);
            indeg[v[1]]++;
        }
        kahn(num);
        reverse(topo.begin(),topo.end());
        if(topo.size()==num) return topo;
        return {};
    }
};