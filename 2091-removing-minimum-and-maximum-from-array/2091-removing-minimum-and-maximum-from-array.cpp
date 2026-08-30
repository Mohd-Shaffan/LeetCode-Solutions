class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        //AYUSH BHAI COMMENTS DEKHKE Y MT MSJHNA COPY PASTE KIYA H HAHAHAHA :)
        int mx=0;
        int mn=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[mx]) mx=i;
            if(nums[i]<nums[mn]) mn=i;
        }
        //case1 both from front
        int front=max(mn,mx) +1;
        //case2 both from last
        int last=min(mn,mx);
        last=nums.size()-last;
        //case3 one from first and other from last 
        int f=min(mx,mn);
        int l=max(mx,mn);
        int fnl=(f+1) + (nums.size()-l);
        

        return min({front,last,fnl});

    }
};