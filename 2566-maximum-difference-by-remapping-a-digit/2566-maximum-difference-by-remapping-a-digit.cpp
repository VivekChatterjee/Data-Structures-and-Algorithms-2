#define ll long long
class Solution {
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        int n = s.size();
        string m = "", mi = "";
        bool changed = 0, dec = 0;
        char c = ' ';
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                m += '9';
            }
            else if (s[i] == '9' && !changed || changed)
            {
                m += s[i];
            }
            else
            {
                changed = 1;
                c = s[i];
                m += '9';
            }
            if (s[i] == s[0])
            {
                mi += '0';
            }
            else
                mi += s[i];
        }
        ll mini = stoll(mi), maxi = stoll(m);
        return maxi - mini;
    }
};