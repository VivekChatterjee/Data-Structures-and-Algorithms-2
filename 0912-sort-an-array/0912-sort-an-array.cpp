class Solution {
public:
    void merge(int s, int mid, int e, vector<int>&nums)
    {
        vector<int>left(mid-s+1), right(e-mid);
        int k=0;
        for(int i=s; i<=mid; i++) left[k++]=nums[i];
        k=0;
        for(int i=mid+1; i<=e; i++) right[k++]=nums[i];
        k=0;
        int l=0, st=s;
        while(k<left.size() && l<right.size())
        {
            if(left[k]<=right[l])
            {
                nums[st++]=left[k];
                k++;
            }
            else
            {
                nums[st++]=right[l];
                l++;
            }
        }
        while(k<left.size())
            nums[st++]=left[k++];
        while(l<right.size())
            nums[st++]=right[l++];
    }
    void breakArray(int s, int e, vector<int>&nums)
    {
        if(s<e)
        {
            int mid=s+(e-s)/2;
            breakArray(s, mid, nums);
            breakArray(mid+1, e, nums);
            merge(s, mid, e, nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        breakArray(0, n-1, nums);
        return nums;
    }
};