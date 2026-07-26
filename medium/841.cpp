class Solution {
public:
    vector <int> vis;
    vector <int> opened;
    void dfs(int room, vector<vector<int>>& rooms){
        vis[room]=1;
        opened.push_back(room);
        for(auto keys:rooms[room]){
            if(!vis[keys]){
                dfs(keys,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vis.assign(n,0);
        dfs(0,rooms);
        return opened.size()==n;        
    }
};