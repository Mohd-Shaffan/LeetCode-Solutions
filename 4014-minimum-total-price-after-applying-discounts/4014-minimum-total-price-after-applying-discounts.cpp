class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int n=prices.size();
        int m =discounts.size();
        double ans=0.0;
        int i=n-1;
        int j =m-1;
        int k=min(n,m)-1;
        while(k>=0){
            ans+= (double)((double)(prices[i])*(double)(100.0-discounts[j])/(double)(100.0));
            i--;j--;
            k--;
            
        }
        if(j<0 && i>=0){
            for(int p=0;p<=i;p++){
                ans+=prices[p];
            }
        }
        return (double)(ans);
    }
};