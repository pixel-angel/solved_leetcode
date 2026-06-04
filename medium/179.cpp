class Solution {
public:
    static bool comparator(string a, string b){
        return a + b > b + a;
        //uske hissab se sort krnenge jiska combination bda hoga.
    }
    string largestNumber(vector<int>& nums) { 
        //convert to strings and compare.
        vector <string> nos;
        for(int i:nums){
            nos.push_back(to_string(i));
        }
        sort(nos.begin(),nos.end(),comparator);

        // edge case: all zeros
        if(nos[0] == "0") return "0";

        string ans="";
        for(string s :nos){
            ans+=s;
        }
        return ans;
    }
};