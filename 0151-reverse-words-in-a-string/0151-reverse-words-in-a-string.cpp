class Solution {
public:
    void reverse(string &s,int lo,int hi){
        while(lo<=hi){
            swap(s[lo],s[hi]);
            lo++;hi--;
        }
    } 
    string reverseWords(string s) {
        stringstream ss(s); string word; s = "";
        while(ss >> word) s += word + " ";
        if(!s.empty()) s.pop_back();
        int n=s.size();

        int start=0;
        for(int end=0;end<s.size();end++){
            if(s[end]==' '){
                reverse(s,start,end-1);
                start=end+1;
            }
        }
        reverse(s,start,n-1);
        reverse(s,0,n-1);
        return s;
    }
};