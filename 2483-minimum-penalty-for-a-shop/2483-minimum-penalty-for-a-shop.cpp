class Solution
{
public:
    int bestClosingTime(string cus)
    {
        int n = cus.length() - 1;
        int penalty = 0;
        for (int i = 0; i <= n; i++)
        {
            if (cus[i] == 'N')
                penalty++;
        }
        int res = n + 1;
        int ans = penalty;
        for (int i = n; i >= 0; i--)
        {
            if (cus[i] == 'N')
                penalty--;
            else
                penalty++;

            if (ans >= penalty)
            {
                res = min(res, i);
                ans = penalty;
            }
        }
        return res;
    }
};