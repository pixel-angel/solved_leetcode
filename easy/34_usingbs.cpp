class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //binary search
        int n=arr.size();
        int s=0,e=n-1;
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            //mtlb ki uss mid index se phele kitne misssing the.
            int missing=arr[mid]-(mid+1);
            //ab if missing k se km h toh aur aage search
            if(missing<k) s=mid+1;
            //if equal or more than k missing toh aage se converge maardo
            else e=mid-1;
        }
        //toh s=> index to till jha pr exactly k missing h
        //toh ans would be s+k
        return s+k;
    }
};