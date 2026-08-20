class Solution {
public:
    void helper(TreeNode* root,vector<int> &v,vector<vector<int>> &ans,int sum){
        if(root==nullptr) return;
        if(!root->left && !root->right && root->val==sum){
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        helper(root->left,v,ans,sum-(root->val));
        helper(root->right,v,ans,sum-(root->val));
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,v,ans,targetSum);
        return ans;
        
    }
};