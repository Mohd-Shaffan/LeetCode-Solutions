class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mp;
        for(int i = 0 ;i < strs.size() ; i++){
            string lexo=strs[i];
            sort(lexo.begin(),lexo.end());
            mp[lexo].push_back(strs[i]);
            
        }
        vector<vector<string>> FinalAns;
        for(const auto &ele : mp){
            FinalAns.push_back(ele.second);
        }
        
        return FinalAns;
    }
};