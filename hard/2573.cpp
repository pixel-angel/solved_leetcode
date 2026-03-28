class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,' ');
        char current='a';
        if(lcp[0][0]!=n) return "";
        for(int i=0;i<n;i++){
            if(ans[i]==' '){
                if(current>'z') return "";
                ans[i]=current;
                for(int j=i+1;j<n;j++){
                    if(lcp[i][j]) ans[j]=ans[i];
                }
                current++;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ans[i]==ans[j]){
                    int expected = (i==n-1||j==n-1)?1:lcp[i+1][j+1]+1;
                    if(lcp[i][j]!=expected) return "";
                }
                else{
                    if (lcp[i][j]!=0) return "";
                }
            }
        }
        return ans;        
    }
};