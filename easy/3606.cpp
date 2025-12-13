class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector <string> electronics;
        vector <string> grocery;
        vector <string> pharmacy;
        vector <string> restaurant;
        int n=code.size();
        for (int i=0;i<n;i++){
            if (isActive[i] && code[i]!=""){
                bool flag=true;
                for (char c:code[i]){
                    if (c=='@' || c=='.' || c=='-'){
                        flag=false;
                        break;
                    }
                }
                if (flag){
                    if (businessLine[i]=="electronics")
                        electronics.push_back(code[i]);
                    else if (businessLine[i]=="grocery")
                        grocery.push_back(code[i]);
                    else if (businessLine[i]=="pharmacy")
                        pharmacy.push_back(code[i]);
                    else if (businessLine[i]=="restaurant")
                        restaurant.push_back(code[i]);
                    else
                        continue;
                }
                
            }
        }
        sort(electronics.begin(),electronics.end());
        sort(grocery.begin(),grocery.end());
        sort(pharmacy.begin(),pharmacy.end());
        sort(restaurant.begin(),restaurant.end());
        for (string a:grocery)
            electronics.push_back(a);
        for (string b:pharmacy)
            electronics.push_back(b);
        for (string c:restaurant)
            electronics.push_back(c);
        return electronics;
    }
};