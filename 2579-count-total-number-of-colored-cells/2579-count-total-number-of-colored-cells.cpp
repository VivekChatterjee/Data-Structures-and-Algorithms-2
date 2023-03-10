#define ll long long
class Solution {
public:
    ll coloredCells(int n)
    {
        ll start = 0, ans = 1;
        if (n == 1)
            return 1;
        ll i=n-1, j=(ll)n*(ll)n, k=i*i;
        return j+k;
    }
};