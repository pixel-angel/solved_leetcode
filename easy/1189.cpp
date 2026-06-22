class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(auto c:text){
            if(c=='b') b++;
            else if(c=='a') a++;
            else if(c=='l') l++;
            else if (c=='o') o++;
            else if (c=='n') n++;
        }
        int ans=min(b,a);
        ans=min(ans,l/2);
        ans=min(ans,o/2);
        ans=min(ans,n);

        return ans;
        
    }
};