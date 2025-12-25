class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        long long ans=0,i=0;
        sort(happiness.begin(),happiness.end());
        while(i<k){
            if ((happiness[n-1-i]-i)>0)
                ans=ans+(happiness[n-i-1]-i);
            if (n-2-i>=0){
                if ((happiness[n-2-i]-i-1)<=0) break;
            }
            i++;
        }
        return ans;
    }
};