class Solution {
public:
    int helper(vector<int> &nums,int i, int k){
        int maxx=INT_MIN;
        for(int j=i;j<=k+i-1;j++){
            maxx=max(maxx,nums[j]);
        }
        return maxx;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        // not an optimal approach o:)
        // vector<int> ans;
        // for(int i=0;i<=n-k;i++){
        //     int max=helper(nums,i,k);
        //     ans.push_back(max);
        // }

        int ngi[n];
        ngi[n-1]=n;
        stack<int> st;
        st.push(n-1);
        // finding next greater idx;
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])  st.pop();
            if(st.empty()) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }
        vector<int> ans;
        int j =0;
        for(int i =0;i<=n-k;i++){
            if(j<i) j=i;
            int mx = nums[j];

            while(j<i+k){
                mx=nums[j];
                if(ngi[j]> i+k) break;
                j=ngi[j];


            }
            ans.push_back(mx);

        }


        return ans;
        
    }
};