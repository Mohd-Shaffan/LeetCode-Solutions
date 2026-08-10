class Solution {
public:
int c=0;
    int reversePair(vector<int> &a,vector<int> &b){
        int count=0;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if((long long)a[i] > 2LL * b[j]) {
                count+=(a.size()-i);
                j++;
            }else{
                i++;
            }

        }
        return count;
    }
    void merge(vector<int> &a,vector<int> &b,vector<int> &res){
        int i=0,j=0,k=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                res[k++]=a[i++];
            }else{
                res[k++]=b[j++];
            }
        }
        while(i<a.size()) res[k++]=a[i++];
        while(j<b.size()) res[k++]=b[j++];
    }
    void mergesort(vector<int> &nums){
        int n=nums.size();
        if(n<=1) return;
        int n1=n/2,n2=n-n1;
        vector<int> a(n1),b(n2);
        for(int i=0;i<n1;i++) a[i]=nums[i];
        for(int i=0;i<n2;i++) b[i]=nums[i+n1];
        mergesort(a);
        mergesort(b);

        merge(a,b,nums);
        c+=reversePair(a,b);

    }
    int reversePairs(vector<int>& nums) {
        c=0;
        mergesort(nums);
        return c;
        
    }
};