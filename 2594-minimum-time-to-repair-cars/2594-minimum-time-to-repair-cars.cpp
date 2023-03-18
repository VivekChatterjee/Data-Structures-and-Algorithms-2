#define ll long long
#define vi vector<int>
class Solution {
public:
    bool isValid(ll mid, vi ranks, int cars)
    {
        int n = ranks.size();
        ll ct = cars;
        for (int i : ranks)
        {
            ll cur = mid / i;
            ll toDec = floor(sqrt(cur));
            ct -= toDec;
        }
        return ct <= 0;
    }
    long long repairCars(vector<int> &ranks, int cars)
    {
        int n = ranks.size();
        ll s = 0, e = INT_MIN;
        for (int i : ranks)
        {
            e = max(e, (ll)i);
        }
        e *= (ll)cars*(ll)cars;
        ll ans = e;
        while (s <= e)
        {
            ll mid = s + (e - s) / 2;
            if (isValid(mid, ranks, cars))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};