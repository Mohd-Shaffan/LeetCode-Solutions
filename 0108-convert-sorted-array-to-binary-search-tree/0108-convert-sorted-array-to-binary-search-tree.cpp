class Solution {
public:
    TreeNode* helper(vector<int> &nums,int lo, int hi){
        if(lo>hi) return nullptr;
        int mid=lo+(hi-lo)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        if(lo==hi) return root;
        root->left=helper(nums,lo,mid-1);
        root->right=helper(nums,mid+1,hi);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
        
    }
};