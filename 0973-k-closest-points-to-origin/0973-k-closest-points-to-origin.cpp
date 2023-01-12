#define ll long double
class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        ll d1=((ll)a[0]*(ll)a[0]) + ((ll)a[1]*(ll)a[1]);
        ll d2=((ll)b[0]*(ll)b[0]) + ((ll)b[1]*(ll)b[1]);
        return d1<d2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>>ans;
        for(int i=0; i<k; i++) ans.push_back(points[i]);
        return ans;
    }
};