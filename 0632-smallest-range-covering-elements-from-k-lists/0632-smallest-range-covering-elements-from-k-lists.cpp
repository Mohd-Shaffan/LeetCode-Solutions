class Solution {
public:
    typedef pair<int , pair< int,int > > pp;// num, i, j;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pp , vector<pp> , greater<pp> > pq;
        int mx=INT_MIN;
        for(int i =0 ;i < nums.size(); i++){
            int ele=nums[i][0];
            mx=max(mx,ele);
            pq.push({nums[i][0],{i,0}});
        }
        
        int range=INT_MAX;
        int st=INT_MIN;
        int end=INT_MAX;
        while(true){
            auto peak=pq.top();
            pq.pop();
            
            int mn=peak.first;
            int rn=mx-mn;
            if(rn<range){
                range=rn;
                st=mn;
                end=mx;
            }else if(rn==range){
                if(st>mn){
                     st=mn;
                     end=mx;
                }
            }
            if(peak.second.second+1>=nums[peak.second.first].size()) break;
            
            int val=nums[peak.second.first][peak.second.second+1];
            if(val>mx) mx=val;
            pq.push({val,{peak.second.first,peak.second.second+1}});
        }
        return {st,end};
    }
};