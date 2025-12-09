//time limit exceeded tho. but my solution
class Solution {
public:
    int specialTriplets(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        for (int j=1;j<n-1;j++){
            int ic=0,kc=0;
            for (int i=0;i<j;i++){
                if(nums[i]==2*nums[j])
                    ic++;
            }
            for (int k=j+1;k<n;k++){
                if(nums[k]==2*nums[j])
                    kc++;
            }
            sum+=ic*kc;
        }
        return sum;
    }
};

//using unordered map:
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long mod=1e9 +7;
        unordered_map <int,int> numCnt;
        unordered_map <int,int> numPartialCnt;

        for(int v:nums){
            numCnt[v]++;
        }
        long long ans=0;
        for (int v:nums){
            long long target=(long long)v*2;
            long long lcnt=numPartialCnt[target];
            numPartialCnt[v]++;
            long long rcnt=numCnt[target]- numPartialCnt[target];
            ans=(ans+lcnt*rcnt)%mod;
        }
        return ans;
    }
};