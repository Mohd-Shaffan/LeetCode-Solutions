class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int> w1;
        unordered_map<char,int> w2;
        for(int i=0;i<word1.size();i++){
            w1[word1[i]]++;
            w2[word2[i]]++;
        }
        for(auto ele : w1){
            if(w2.find(ele.first)==w2.end()) return false;
        }
        unordered_map<int,int> f1;
        unordered_map<int,int> f2;
        for(auto ele : w1){
            f1[ele.second]++;
        }
        for(auto ele : w2){
            f2[ele.second]++;
        }
        
        return f1==f2;
        
    }
};