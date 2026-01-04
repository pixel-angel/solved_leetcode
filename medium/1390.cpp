class Solution {
public:
    int sumofdivisors(int a){
        int sum=1+a;
        int count=2;
        for (int i=2;i*i<=a;i++){
            if(a%i==0){
                sum+=i;
                count++;
                if(a/i!=i){ sum+=a/i; count++;}
            }
            if(count>4){
                return 0;
            }
        }
        if(count==4)return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int s=0;
        for (int i:nums){
            s+=sumofdivisors(i);
        }
        return s;   
    }
};