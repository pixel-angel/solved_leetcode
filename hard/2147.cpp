class Solution {
public:
    int numberOfWays(string corridor) {
       long long mod=1e9+7;
       long long ans=1;
       int total_seat=0;
       int plant_cnt=0;
       for (char c:corridor){
        if (c=='S'){
            total_seat++;
            if (total_seat % 2 == 0) {
                    ans = (ans * (plant_cnt + 1)) % mod;
                    plant_cnt = 0;
                }
        }
        else if(c=='P' && (total_seat%2==0) && total_seat!=0){
            plant_cnt++;
        }
       }
        if (total_seat%2!=0 || total_seat==0){
            return 0;
        }
        return ans%mod;
    }
};