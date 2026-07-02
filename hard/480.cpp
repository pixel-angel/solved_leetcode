class Solution {
public:
    struct bag {
        multiset<int> left, right;

        void balance() {
            while (left.size() > right.size() + 1) {
                right.insert(*prev(left.end()));
                left.erase(prev(left.end()));
            }

            while (left.size() < right.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        }

        void add(int x) {
            if (left.empty() || x <= *prev(left.end()))
                left.insert(x);
            else
                right.insert(x);

            balance();
        }

        void remove(int x) {
            auto it = left.find(x);
            if (it != left.end())
                left.erase(it);
            else
                right.erase(right.find(x));

            balance();
        }

        double median(int k) {
            if (k & 1)
                return *prev(left.end());
            return ((double)*prev(left.end()) + *right.begin()) / 2.0;
        }
    };
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        bag b;
        vector<double> ans;
        for (int i = 0; i < nums.size(); i++) {
            b.add(nums[i]);
            if ((i - k) >= 0)
                b.remove(nums[i - k]);
            if (i >= (k - 1))
                ans.push_back(b.median(k));
        }
        return ans;
    }
};