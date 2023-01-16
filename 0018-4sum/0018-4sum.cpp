#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0; i<n; i++)
        {
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
                    }
                    else if((ll)sum<t) s++;
                    else e--;
                }
            }
        }
        return ans;
    }
};