#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<ll, ll>>v;
        for(int i=0; i<n; i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), greater<pair<ll, ll>>());
        ll i=0, cur=0, ans=0;
        priority_queue<ll, vector<ll>, greater<ll>>p;
        while(i<n)
        {
            cur+=v[i].second;
            p.push(v[i].second);
            if(p.size()==k)
            {
                ans=max(ans, cur*v[i].first);
                cur-=p.top();
                p.pop();
            }
            i++;
        }
        return ans;
    }
};