class Solution {
public:
    int helper(vector<int> &nums,vector<int> &dp,int n,int i){
        if(i==n-1) return nums[n-1];
        if(i==n-2) return max(nums[n-1],nums[n-2]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max((nums[i] + helper(nums,dp,n,i+2)),(helper(nums,dp,n,i+1)));
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n,-1);
      return helper(nums,dp, n,0);
    }
};