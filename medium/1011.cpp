class Solution {
public:
    bool check(int mid, vector<int>&w, int days){
        int sum=0;
        int d=1;
        for(int i:w){
            if(sum+i<=mid){
                sum+=i;
            }
            else{
                sum=i;
                d++;
            }
            if(d>days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        int mid;
        int ans;
        while(s<=e){
            mid=s+(e-s)/2;
            if(check(mid,weights,days)){
                //go left since min.
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
        
        
    }
};