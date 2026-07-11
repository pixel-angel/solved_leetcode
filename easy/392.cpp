class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(j<t.size()){
            if(s[i]==t[j]) i++;
            j++;
        }
        int n=s.size();
        return i==n;
        
    }
};