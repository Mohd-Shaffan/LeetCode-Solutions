class Solution {
public:
    int levels(TreeNode* root){
        if(root==nullptr) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxLevels=levels(root->left)+levels(root->right);
        
        return max(maxLevels,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        
        
    }
};