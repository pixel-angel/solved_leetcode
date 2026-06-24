class KthLargest {
public:
    int k;
    // vector <int> nums;
    priority_queue <int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        
        //the idea is to store only the top k. and since min heap h. 
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k) pq.pop(); //i.e. sbse chhota waala nikal diya.
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k) pq.pop();
        return pq.top();        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */