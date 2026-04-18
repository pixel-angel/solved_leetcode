class Solution {
public:
    long long reverse(int n){
        long long ans=0;
        while(n){
            ans=ans*10+n%10;
            n/=10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};