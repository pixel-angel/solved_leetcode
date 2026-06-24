class Solution {
public:

    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {

            int da = a[0] * a[0] + a[1] * a[1];
            int db = b[0] * b[0] + b[1] * b[1];

            return da > db;  // min heap
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            cmp
        > pq;

        for(auto &p : points) {
            pq.push(p);
        }

        vector<vector<int>> ans;

        while(k--) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};