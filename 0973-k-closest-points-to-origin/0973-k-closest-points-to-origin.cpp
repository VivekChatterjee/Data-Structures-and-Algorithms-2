#define ll long double
#define pii pair<ll, pair<int, int>>
class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b)
    {
        ll d1=((ll)a[0]*(ll)a[0]) + ((ll)a[1]*(ll)a[1]);
        ll d2=((ll)b[0]*(ll)b[0]) + ((ll)b[1]*(ll)b[1]);
        if(d1 <= d2) return 1;
        else return 0;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort(points.begin(), points.end(), cmp);
        priority_queue<pii, vector<pii>, greater<pii>>p;
        for(auto i: points)
        {
            ll d=((ll)i[0]*(ll)i[0]) + ((ll)i[1]*(ll)i[1]);
            p.push({d, {i[0], i[1]}});
        }
        vector<vector<int>>ans;
        while(ans.size()<k)
        {
            ans.push_back({p.top().second.first, p.top().second.second});
            p.pop();
        }
        // for(int i=0; i<k; i++) ans.push_back(points[i]);
        return ans;
    }
};