#define vi vector<int>
#define pb push_back
class Solution {
public:
    int splitNum(int num)
    {
        vi v;
        while (num)
        {
            v.pb(num % 10);
            num /= 10;
        }
        sort(v.begin(), v.end());
        int i = 0, j = 0;
        for (int k = 0; k < v.size(); k++)
        {
            if (k % 2)
            {
                i = i * 10 + v[k];
            }
            else
            {
                j = j * 10 + v[k];
            }
        }
        return i + j;
    }
};