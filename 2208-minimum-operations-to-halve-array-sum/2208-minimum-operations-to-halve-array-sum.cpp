#define ll long double
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<ll>p;
        ll sum = 0;
        for(auto i: nums)
        {
            p.push((ll)i);
            sum+=(ll)i;
        }
        ll reduced = 0;
        ll ans = 0;
        while(reduced < sum/2)
        {
            ll top = p.top();
            p.pop();
            p.push(top/2);
            reduced += (top - top/2);
            ans++;
        }
        return ans;
    }
};