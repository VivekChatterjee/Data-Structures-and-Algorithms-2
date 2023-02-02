class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // there can be only be max of 2 majority element in an array
        int c1=0, c2=0, a=0, b=0, n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] == a) c1++;
            else if(nums[i] == b) c2++;
            else if(!c1) { a=nums[i], c1=1; }
            else if(!c2) { b=nums[i], c2=1; }
            else { c1--, c2--; }
        }
        c1=0, c2=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == a) c1++;
            if(nums[i] == b) c2++;
        }
        vector<int>ans;
        if(c1 > n/3) ans.push_back(a);
        if(b != a && c2 > n/3) ans.push_back(b);
        return ans;
    }
};