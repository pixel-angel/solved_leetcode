class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int ans=0;
        int apples=0;
        for (int i:apple) apples=apples+i;
        sort(capacity.begin(),capacity.end());
        int i=capacity.size()-1;
        while(apples>0){
            ans++;
            apples=apples-capacity[i];
            i--;
        }
        return ans;
    }
};