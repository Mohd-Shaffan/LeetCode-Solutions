class Solution {
public:
    void helper(TreeNode* root,long long sum,int &count){
        if(root==nullptr) return;
        if((long long )(root->val)==sum) count++;
        helper(root->left,sum-(long long)(root->val),count);
        helper(root->right,sum-(long long)(root->val),count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        int count=0;
        helper(root,targetSum,count);
        count+=pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
        return count;
    }
};