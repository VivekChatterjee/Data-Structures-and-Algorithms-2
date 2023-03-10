#define ll long long
#define vi vector<int>
class Solution {
public:
    vector<int> divisibilityArray(string word, int m)
    {
        ll n = word.size(), num = 0;
        string s = "";
        vi ans(n);
        ll mm = (ll)m;
        for (ll i = 0; i < n; i++)
        {
            s += word[i];
            num = (stoll(s)) % mm;
            s = to_string(num);
            if (num == 0)
                ans[i] = 1;
            else
                ans[i] = 0;
        }
        return ans;
    }
};