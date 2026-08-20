
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root==nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            if(temp->left) s.push(temp->left);
            if(temp->right) s.push(temp->right);
            
        }
        int n =ans.size();
        
            int i=0;
            int j=n-1;
            while(i<=j){
                swap(ans[i],ans[j]);
                i++;j--;
            }
       
        return ans;
    }
};