class Solution {
public:

    string tree2str(TreeNode* root) {
        if(root==nullptr) return "";

        string result=to_string(root->val);
        string LEFT= tree2str(root->left);
        string RIGHT= tree2str(root->right);

        if(!root->left && !root->right){
            return result;

        }
        if(!root->left){
            return result + "()"+"(" + RIGHT +")";
        }
        if(root->right==nullptr){
            return result + "("+ LEFT +")";
        
        }
        return result + "("+ LEFT +")"+"(" + RIGHT+")";
    }
};