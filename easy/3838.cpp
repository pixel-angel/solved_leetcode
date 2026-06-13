class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto word:words){
            int tot=0;
            for(auto c:word){
                tot+=weights[c-'a'];
            }
            //ab reverse order me add krna h 
            tot=tot%26;
            //like agar 3 h toh w aana chahiye. toh 'z' -3 krungi toh 
            ans+=('z'-tot);
        }
        return ans;
        
    }
};