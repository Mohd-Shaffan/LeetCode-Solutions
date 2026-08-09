class Solution {
public:
    int helper(int n ){
        int product=1;
        while(n>0){
            product*=(n%10);
            n/=10;
        }
        return product;

    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<120;i++){
            if(helper(i)%t==0) return i;
        }
        return -1;
    }
};