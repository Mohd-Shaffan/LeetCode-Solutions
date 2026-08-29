class Solution {
public:
    vector<int> dp;
    int f(vector<int> &coins,int amount){
        if(amount==0) return 0;
        
        if(dp[amount]!=-1) return dp[amount];
        int result=INT_MAX-1;
        for(int i =0 ; i <coins.size(); i++){
            if(amount-coins[i]<0) continue;
            result= min(result,f(coins,amount-coins[i]));

        }
        return dp[amount]=1+ result;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==1 && amount%coins[0]!=0 ) return -1;
        int n =coins.size();
        dp.clear();
        dp.resize(1000006,-1);
        int res=f(coins,amount);
        return (res!=INT_MAX)? res : -1;
        
    }
};