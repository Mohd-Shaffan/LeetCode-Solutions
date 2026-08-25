class Solution {
public:
    TreeNode* st=nullptr;
    void find(TreeNode* root,int val){
        if(!root) return;
        if(root->val==val){
             st= root;
             return;
        }
        find(root->left,val);
        find(root->right,val);
        
    }
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        if(!root) return;
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        markParent(root->left,mp);
        markParent(root->right,mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root,start);
        unordered_map<TreeNode*,TreeNode*> mp;
        markParent(root,mp);
        unordered_set<TreeNode*> isInfected;
        isInfected.insert(st);
        queue< pair<TreeNode*,int> > q;
        q.push({st,0});
        int level;
        while(!q.empty()){
            TreeNode* temp=(q.front()).first;
            level=(q.front()).second;
            q.pop();
            isInfected.insert(temp);
            if(temp->left){
                if(isInfected.find(temp->left)==isInfected.end()){
                    q.push({temp->left,level+1});
                    isInfected.insert(temp->left);
                }
            }
            if(temp->right){
                if(isInfected.find(temp->right)==isInfected.end()){
                    q.push({temp->right,level+1});
                    isInfected.insert(temp->right);
                }
            }
            if(mp.find(temp)!=mp.end()){
                if(isInfected.find(mp[temp])==isInfected.end()){
                    q.push({mp[temp],level+1});
                    isInfected.insert(mp[temp]);
                }
            }
            
        }
        return level;
    }
};