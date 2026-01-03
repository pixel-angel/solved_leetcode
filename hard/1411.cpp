class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;
        long same = 6; 
        long diff = 6; 

        for (int i = 2; i <= n; i++) {
            long newSame = (same * 3 + diff * 2) % mod;
            long newDiff = (same * 2 + diff * 2) % mod;
            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % mod;        
    }
};