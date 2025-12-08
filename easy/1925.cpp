class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        int x;
        for (int i=1;i<=n;i++){
            for (int j=1;j<n;j++){
                if (j*j>i*i)
                    break;
                for(int k=1;k<n;k++){
                    x=j*j+k*k;
                    if (x>i*i)
                        break;
                    if (x==i*i)
                        ans++;
                }
            }
        }
        return ans;
    }
};