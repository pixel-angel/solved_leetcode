class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        vector <int> ans;
        string s="123456789";
        int st=to_string(low).size();
        int en=to_string(high).size();
        for(int i=st;i<=en;i++){
            //get i length ke substrings.
            for(int j=0;j<10-i;j++){
                string num=s.substr(j,i);
                int n=stoi(num);
                if(n>=low && n<=high){
                    ans.push_back(n);
                }
            }
        }
        return ans;

        
    }
};