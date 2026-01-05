class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mini=INT_MAX, count=0;
        for (auto& row:matrix){
            for(int x:row){
                mini=min(mini,abs(x));
                if(x<0){
                    sum-=x;
                    count++;
                }
                else{
                    sum+=x;
                }
            }
        }
        if (count%2==1) return sum-2*mini;
        else return sum;
    }
};