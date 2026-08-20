class Solution {
public:
    
    int level(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+ max(level(root->left),level(root->right));
    }
    
    void levelOrder(TreeNode* root,int curr,int lvl,vector<int> &ans){
        if(root==nullptr) return;
        if(curr==lvl){
            ans[curr]=root->val;
            return;
        }
        levelOrder(root->left,curr+1,lvl,ans);
        levelOrder(root->right,curr+1,lvl,ans);
    }
    void allLevels(TreeNode* root,int lvl,vector<int> &ans){
        if(root==nullptr) return;
        for(int i=0;i<=lvl;i++){
            levelOrder(root,0,i,ans);   
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        int n = level(root);
        vector<int> ans(n,-1);
        allLevels(root,n-1,ans);
        
        
        return ans;
        
        
    }
};