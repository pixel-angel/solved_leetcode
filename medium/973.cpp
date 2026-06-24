class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                       greater<pair<int, vector<int>>>>pq;
        for (auto i : points) {
            int x2 = i[0] * i[0];
            int y2 = i[1] * i[1];
            pq.push({x2 + y2, i});
        }
        for (int i = 1; i <= k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};