class Solution {
public:
    typedef pair< double , pair<int,int> >  p;
    vector<vector<int>> kClosest(vector<vector<int>>& nums, int k) {
        vector<p> d;
        for( auto ele : nums ){
            int i = ele[0]*ele[0];
            int j = ele[1]*ele[1];
            double di=(i+j);
            p x;
            x.first=di;
            x.second={ele[0],ele[1]};
            d.push_back(x);

        }
        priority_queue<p> pq;
        for(auto ele  : d){
            pq.push(ele);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        vector<vector<int>> Finalans;
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            ans.push_back((ele.second).first);
            ans.push_back((ele.second).second);

            Finalans.push_back(ans);
            ans.clear();
        }
        
        return Finalans;
        
    }
};