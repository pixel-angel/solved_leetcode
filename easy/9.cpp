class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int rmndr,n=x;
        long int ans=0;
        while(x>0){
            rmndr=x%10;
            ans=ans*10+rmndr;
            x=x/10;
        }
        if (ans==n){
            return true;
        }
        else
            return false;
    }
};