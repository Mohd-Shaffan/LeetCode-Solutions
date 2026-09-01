class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';

        int len= (1 << n) -1;
        if(k<ceil(len/2.0)){
           return findKthBit(n-1,k);

        }else if(k==ceil(len/2.0)) 
            return '1';
        else{//k>len/2
            char ch=findKthBit(n-1,len-(k-1));
            return (ch=='1')? '0' : '1';
        }

    }
};