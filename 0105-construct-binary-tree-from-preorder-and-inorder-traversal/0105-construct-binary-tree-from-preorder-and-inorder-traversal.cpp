class Solution {
public:
    TreeNode* helper(vector<int>& pre,int pl ,int ph ,vector<int>& in,int inl,int inh){
        if(pl>ph) return nullptr;
        TreeNode* root=new TreeNode(pre[pl]);
        if(pl==ph) return root;
        int i=inl;
        while(i<=inh){
            if(in[i]==pre[pl]) break;
            i++;
        }
        int lc=i-inl;
        int rc=inh-i;
        root->left=helper(pre,pl+1,pl+lc,in,inl,i-1);
        root->right=helper(pre,pl+lc+1,ph,in,i+1,inh);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= inorder.size();
       return helper(preorder,0,n-1,inorder,0 ,n-1);
        
    }
};