class Solution {
public:
    bool isPalindrome(string s) {
        string snew;
        for(char c : s){
            if(isalnum(c)){
                snew += tolower(c);
            }
        }

        for(int i = 0; i < snew.size()/2; i++){
            if(snew[i] != snew[snew.size()-i-1]) return false;
        }
        return true;
    }
};