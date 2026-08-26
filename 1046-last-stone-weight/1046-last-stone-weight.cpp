class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int> pq;
        
        for(int ele : nums){
            pq.push(ele);
        }
            while(pq.size()>1){
                int y=pq.top();
                pq.pop();
                int x=pq.top();
                pq.pop();
                if(y!=x) pq.push(y-x);

            }
        
        if(!pq.empty()) return pq.top();
        return 0;
        
    }
};