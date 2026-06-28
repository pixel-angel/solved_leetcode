class Solution {
public:
    string removeOuterParentheses(string s) {
        stack <int> st;
        int i=0;
        while(i<s.size()){
            if(s[i] =='(')  st.push(i);
            else if(st.size()==1){
                s.erase(st.top(),1);
                i--;
                s.erase(i,1);
                i--;
                st.pop();
            }
            else st.pop();
            i++;
        }
        return s;
    }
};