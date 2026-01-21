class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector <int> arr;
        for(int x:nums){
            int flag=1;
            for(int i=0;i<x;i++){
                if((i|(i+1))==x){
                    arr.push_back(i);
                    flag=0;
                    break;
                }
            }
            if (flag==1) arr.push_back(-1);
        }
        return arr;        
    }
};

