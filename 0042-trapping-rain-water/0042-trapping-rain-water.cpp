class Solution {
public:
    int trap(vector<int>& height) {
      int n = height.size();  
      //prev greatest element
      int prevs[n];
      prevs[0]=-1;
      int max=height[0];
      for (int i=1;i<n;i++){
        prevs[i]=max;
        if(max<height[i]) max=height[i]; 
      }
      //next greatest elment
      int next[n];
      next[n-1]=-1;
      max=height[n-1];
      for(int i=n-2;i>=0;i--){
        next[i]=max;
        if(max<height[i]) max=height[i];
      }
      //minimum array 
      for(int i=0;i<n;i++) prevs[i]=min(prevs[i],next[i]);
      //calculating water
      int water=0;
      for (int i=1;i<n-1;i++){
        
        if(height[i]<prevs[i]) water+=(prevs[i]-height[i]);
      }
      return water;


    }
};