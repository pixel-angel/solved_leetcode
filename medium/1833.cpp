class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map <int,int> count;
        for(auto i:costs){
            count[i]++;
        }
        int ans=0;
        for(auto i:count){
            int poss=min(coins/i.first,i.second);
            if(poss==0) break;
            else {
                ans+=poss;
                coins-=poss*i.first;    
            }
        }
        return ans;
        
    }
};