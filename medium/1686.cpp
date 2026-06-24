class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector <pair<int,int>> sum(n);
        for(int i=0;i<n;i++){
            sum[i]={aliceValues[i]+bobValues[i],i};
        }
        sort(sum.rbegin(),sum.rend());
        int alice=0;
        int bob=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                alice+=aliceValues[sum[i].second];
            }
            else bob+=bobValues[sum[i].second];
        }
        if(alice>bob) return 1;
        else if(bob>alice) return -1;
        return 0;
        
    }
};