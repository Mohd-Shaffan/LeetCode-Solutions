class Solution {
public:
    int helper(int sr,int sc,int er,int ec,vector<vector<int>> &dp,vector<vector<int>>& grid){
        if(sr>er || sc > ec) return 0 ;
        if(grid[sr][sc]==1) return 0;
        if(sr==er && sc==ec){
            return 1;
        }
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        return dp[sr][sc]=helper(sr,sc+1,er,ec,dp,grid) + helper(sr+1,sc,er,ec,dp,grid);

    }


    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(0,0,m-1,n-1,dp,grid);

    }
};