class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=n;
        long long count=1;
        for (int i=0;i<n-1;i++){
            if(prices[i]-prices[i+1]==1){
                count++;
            }
            else{
                ans+=(((count-1)*count)/2);
                count=1;
            }
        }
        ans += (count * (count - 1)) / 2;
        return ans;

        
    }
};