class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map <char,vector<char>> mp;
        mp['1']={};
        mp['2']={'a','b','c'}; mp['3']={'d','e','f'}; mp['4']={'g','h','i'};
        mp['5']={'j','k','l'}; mp['6']={'m','n','o'}; mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'}; mp['9']={'w','x','y','z'};
        int n=digits.size();
        vector <vector<string>> dp(n);
        for(int i=0;i<n;i++){
            int d=digits[i];
            vector <string> curr;
            if(i==0){
                for(auto c:mp[d]){
                    curr.push_back(string(1,c));
                }
                dp[0]=curr;
            }
            else{
                for(auto s:dp[i-1]){
                    for(auto c:mp[digits[i]]){
                        curr.push_back(s+c);
                    }
                }
                dp[i]=curr;
            }
        }
        return dp[n-1];        
    }
};