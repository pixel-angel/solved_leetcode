class Solution {
public:
    int binary_search(int n, vector<int>& nums2){
        int st = 0, end = nums2.size() - 1;
        int ans = -1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(nums2[mid] >= n){
                ans = mid;        
                st = mid + 1;     
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        for(int i = 0; i < nums1.size(); i++){
            int j = binary_search(nums1[i], nums2);
            if(j >= i) {
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};

//mthd 2
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, ans = 0;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ans = max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};

/mthd 3
class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i, j = 1;

        for (i = 0; i < A.size() && j < B.size(); j++)
            i += A[i] > B[j];

        return j - i - 1;
    }
};