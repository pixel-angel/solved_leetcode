class Solution {
public:
    int mySqrt(int x) {
        int s=0,e=x;
        long long int mid= s+(e-s)/2;
        long long int ans,sq;
        while (s<=e){
            sq = mid*mid;
            if (x==sq)
                return mid;
            else if (sq <x){
                ans=mid;
                s=mid+1;
            }
            else
                e=mid-1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};