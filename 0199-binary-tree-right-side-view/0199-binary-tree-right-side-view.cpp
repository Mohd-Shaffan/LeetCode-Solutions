class Solution {
public:
    
    int level(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+ max(level(root->left),level(root->right));
    }
    void preorder(TreeNode* root,int lvl,vector<int> &ans){
        if(root==nullptr) return;
        ans[lvl]=root->val;
        
        preorder(root->left,lvl+1,ans);
        preorder(root->right,lvl+1,ans);
        
    }
   
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        int n = level(root);
        vector<int> ans(n,-1);
        preorder(root,0,ans);
        
        
        return ans;
        
        
    }
};