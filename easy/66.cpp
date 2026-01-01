class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        bool flag=true;
        while (n-1>=0){
            if (digits[n-1]==9){
                digits[n-1]=0;
                n--;
            }
            else{
                digits[n-1]+=1;
                flag=false;
                break;
            }
        }
        if (flag) digits.insert(digits.begin(),1);
        return digits;  
    }
};