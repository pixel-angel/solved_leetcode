class Solution {
public:
    int firstOcc(vector <int>& nums,int n, int target){
        int s=0,e=n-1;
        int mid= s+(e-s)/2;
        int ans=-1;

        while (s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(target>nums[mid]){//right me jao
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    int lastOcc(vector <int>& nums,int n, int target){
        int s=0,e=n-1;
        int mid= s+(e-s)/2;
        int ans=-1;

        while (s<=e){
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(target>nums[mid]){//eight me jao
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int f=firstOcc(nums ,n, target);
        int l=lastOcc(nums,n, target);
        vector <int> ans={f,l};

        return ans;

    
    }
};