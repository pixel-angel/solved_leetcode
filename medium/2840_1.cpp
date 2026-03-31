class Solution {
public:
    bool checkStrings(string s1, string s2) {
        multiset <char> s1even,s1odd,s2even,s2odd;
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(i%2){
                //odd
                s1odd.insert(s1[i]); s2odd.insert(s2[i]);
            }
            else{
                s1even.insert(s1[i]); s2even.insert(s2[i]);
            }
        }
        return (s1odd == s2odd) && (s1even == s2even);        
    }
};