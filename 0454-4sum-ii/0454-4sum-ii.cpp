class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
    vector<int>& nums4) {
        int n=nums1.size(), ans=0;
        unordered_map<int, int>fTwo;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                fTwo[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans+=fTwo[-(nums3[i] + nums4[j])];
            }
        }
        return ans;
    }
};