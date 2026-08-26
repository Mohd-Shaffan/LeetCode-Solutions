class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto ele : nums ) mp[ele]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto ele : mp){
            pq.push({ele.second,ele.first});
            if(pq.size()>k) pq.pop();
            
        }
        vector<int> ans(k,0);
        for(int i =0 ;i < k ; i++){
            

            ans[i]=((pq.top()).second);
            pq.pop();
        }

        return ans;
        
    }
};