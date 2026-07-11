class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> final(n+m);
        int k=0,i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                final[k]=nums1[i];
                i++;
            }
            else{
                final[k]=nums2[j]; j++;
            }
            k++;
        }
        if(i<m){
            while(i<m){
                final[k]=nums1[i];
                k++;i++;
            }
        }
        else if(j<n){
            while(j<n){
                final[k]=nums2[j];
                j++;k++;
            }
        }
        nums1=final;
        
        
        
    }
};