class Solution {
public:
    bool check(vector<int>&nums, int t,int mid){
        int sum=0;
        for(auto i:nums){
            sum+=i/mid;
            if(i%mid!=0) sum++;
            if(sum>t) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        //isme sample space would be 1 to max of nums ?
        int s=1, e=*max_element(nums.begin(),nums.end());
        int mid;
        int ans=1;
        //har mid pr check krenge ki voh ans h ki nhi. ab agar nhi h toh divisor bda chahiye 
        //means its 00000111 and find first one
        //i.e agar h toh go left. 
        while(s<=e){
            mid=s+(e-s)/2;
            if(check(nums,threshold,mid)){
                //go left
                ans=mid;
                e=mid-1;
            }
            else{
                //go right
                s=mid+1;
            }
        }
        return ans;        
    }
};