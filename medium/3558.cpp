class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long binpow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        //maked adj matrix

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //dfs
        stack<pair<int,int>> st;
        vector<int> vis(n + 1, 0);

        st.push({1, 0});
        //to track max depth
        int max_depth = 0;

        while (!st.empty()) {
            auto [node, level] = st.top();
            st.pop();

            if (vis[node]) continue;
            vis[node] = 1;

            max_depth = max(max_depth, level);

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    st.push({nei, level + 1});
                }
            }
        }
        //pnc
        return binpow(2, max_depth - 1);
    }
};