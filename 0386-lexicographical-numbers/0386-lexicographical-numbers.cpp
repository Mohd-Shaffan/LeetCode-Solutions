class Solution {
public:
    vector<int> result;
    void solve(int curr,int n ){
        if(curr>n) return ;
        result.push_back(curr);
        for(int i=0;i<=9;i++){
            int newCurr= (curr*10)+i;
            if(newCurr>n) return;
            else solve(newCurr,n);
        }




    }
    vector<int> lexicalOrder(int n) {
        result.clear();
        for(int i=1;i<=9;i++){
            solve(i,n);
        }
        return result;
    }
};