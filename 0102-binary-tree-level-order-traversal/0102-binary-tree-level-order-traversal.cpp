class Solution {
public:
    int levels(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void perLevel(TreeNode* root,int curr,int lvl,vector<int> &ans){
        if(root == nullptr) return;
        if(curr==lvl){
            ans.push_back(root->val);
            return;
        }
        perLevel(root->left,curr+1,lvl,ans);
        perLevel(root->right,curr+1,lvl,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalAns;
        vector<int> ans;
        int n = levels(root);
        for(int i=0;i<n;i++){
            perLevel(root,0,i,ans);
            finalAns.push_back(ans);
            ans.clear();
        }
        return finalAns;
        
    }
};