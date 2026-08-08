class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,-1);
        int k=0;
        int j=1;
        for(int i=0;i<=nums.size()-1;i++){
            if(nums[i]>=0){
                result[k]=nums[i];
                k+=2;

            }else{
                result[j]=nums[i];
                j+=2;
            }
        }
        return result;
        
    }
};