class Solution {
public:
    int subtractProductAndSum(int n) {
        int p=1,s=0,rmndr;
        int ans;
        while(n!=0){
            rmndr=n%10;
            p*=rmndr;
            s+=rmndr;
            n=n/10;
        }
        ans=p-s;
        return ans;
        
    }
};