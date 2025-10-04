class Solution {
public:
    int reverse(int x) {
        int newnum=0;
        int rmndr;
        while(x!=0){
            rmndr=x%10;
            if(newnum>INT_MAX/10||(newnum<INT_MIN/10)){
                return 0;
            }
            newnum=newnum*10+rmndr;
            x=x/10;
        }
        return newnum;
        
    }
};