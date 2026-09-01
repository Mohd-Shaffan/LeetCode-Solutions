class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        if(k==1LL) return 'a';
        long long  len=1;
        int n =ops.size();
        long long  newk=-1;
        int opstype=-1;

        for(int i=0;i<n;i++){
            len*=2;
            if(len>=k){
                opstype=ops[i];
                newk=k-len/2;
                break;
            }
        }

        char ch=kthCharacter(newk,ops);

        if(opstype==0) return ch;

        return (ch=='z')? 'a' : ch+1;
        
    }
};