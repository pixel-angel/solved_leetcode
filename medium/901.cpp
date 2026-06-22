class StockSpanner {
public:
    stack <pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans=1;
        if(!st.empty()){    
            while(st.top().first<=price){
                ans+=st.top().second;
                st.pop();
                if(st.empty()) break;
            }
        }
        st.push({price,ans});
        return ans;        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */