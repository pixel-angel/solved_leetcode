class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int s=encodedText.size();
        string ans="";
        int cols=s/rows;
        for(int i=0;i<cols;i++){
            for(int j=i;j<s;j+=cols+1){
                ans+=encodedText[j];
            }
        }
        //triming imp
        while(!ans.empty()&&ans.back()==' ') ans.pop_back();

        return ans;

    }
};