class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx=-1;
        for(int i =0 ;i < arr.size(); i ++ ){
            if(arr[i]==x) {
                idx=i;
                break;
            }
        }
        priority_queue< pair<int,int> > pq;
        vector<int> d(arr.size(),-1);
        for(int i =0 ;i<arr.size();i++){
            d[i]=abs(x-arr[i]);
        }
        for(int i =0; i <d.size();i++){
            pq.push({d[i],arr[i]});
            if(pq.size()>k) pq.pop();
        }
        d.resize(k,-1);
        for(int i = 0; i< k ;i++){
            d[i]=((pq.top()).second);
            pq.pop();
        }
        sort(d.begin(),d.end());
        return d;
        
    }
};