#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), num=nums[0];
        vector<vector<int>>ans;
        set<vector<int>>st;
        if(n<4) return ans;
        for(int i=0; i<n; i++)
        {
            if(i!=0) // this is reducing time
            {
                if(nums[i]==num) continue;
                num=nums[i];
            }
            for(int j=i+1; j<n; j++)
            {
                int s=j+1, e=n-1;
                ll t=(ll)target-((ll)nums[i]+(ll)nums[j]);
                while(s<e)
                {
                    vector<int>v(4);
                    v[0]=nums[i], v[1]=nums[j], v[2]=nums[s], v[3]=nums[e];
                    ll sum=(ll)nums[s]+(ll)nums[e];
                    if(sum == t && st.find(v) == st.end())
                    {
                        ans.push_back(v);
                        st.insert(v);
                        s++;
                        e--;
                    }
                    else if((ll)sum<t) s++;
                    else e--;
                }
            }
        }
        return ans;
    }
};