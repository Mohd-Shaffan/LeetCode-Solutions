class Solution {
public:
    void NSE(int nse[],int n,vector<int> &nums){
        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);            
        }
    }
    void PSE(int pse[],int n,vector<int> &nums){
        stack<int> st;
        pse[0]=-1;
        st.push(0);
        for(int i=1;i<=n-1;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);            
        }
    }
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        int nse[n];
        NSE(nse,n,nums);
        int pse[n];
        PSE(pse,n,nums);
        int MaxArea=0;
        for(int i=0;i<n;i++){
            int breath=nse[i]-pse[i]-1;
            int area=nums[i]*breath;
            MaxArea=max(MaxArea,area);
            
        }
        return MaxArea;
        
    }
};