class Solution {
public:
    string s;
    void helper(int k){
        if(s.size()>=k) return;
        string temp="";
        for(int i=0;i<s.size();i++){
            temp+=(s[i]+1);
        }
        s+=temp;
        helper(k);


    }
    char kthCharacter(int k) {
        s="a";
        helper(k);
        return (char)(s[k-1]);        
        
    }
};