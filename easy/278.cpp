// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s=1,e=n;
        int mid,ans=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(isBadVersion(mid)){
                //agar bura h toh peeche krdo end ko
                ans=mid;
                e=mid-1;
            }
            else{
                //agar achha h toh ek toh voh ans ho skta and aage check kro
                s=mid+1;
            }
        }
        return ans;
        
    }
};