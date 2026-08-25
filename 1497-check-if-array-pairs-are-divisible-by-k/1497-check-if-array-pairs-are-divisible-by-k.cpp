class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int nw,ele;
        unordered_map<int,int> mp;
        for( int ele : arr){
            nw=((ele%k)+k)%k;
            mp[nw]++;
        }
        for(auto &x : mp){
            ele=x.first;
            nw=k-ele;
            if(ele==0 ){
                if(mp[ele]%2!=0)
                 return false;
            }
            else if(mp.find(nw)==mp.end() || mp[ele]!=mp[nw]) return false;
        }
        return true; 
    }
};