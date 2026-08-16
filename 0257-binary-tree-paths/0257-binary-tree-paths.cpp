class Solution {
public:
    void helper(TreeNode* root,vector<string> &ans,string str){
        if(root==nullptr) return;
        int x=root->val;
        string s=to_string(x);
        if(root->left==nullptr && root->right==nullptr){
                str+=s;
                ans.push_back(str);
            return;
        }
        helper(root->left,ans,str+s+"->");
        helper(root->right,ans,str+s+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str="";
        helper(root,ans,str);
        return ans;
    }
};