#define vi vector<int>
class Solution {
public:
    int distMoney(int m, int ch)
    {
        if (m < ch)
            return -1;
        vi v(ch, 1);
        m -= ch;
        for (int i = 0; i < ch; i++)
        {
            if (m >= 7)
            {
                if (i == ch - 1)
                {
                    v[i] += m;
                }
                else
                {
                    v[i] = 8;
                    m -= 7;
                }
            }
            else
            {
                if (i == ch - 1)
                {
                    if (m == 3)
                    {
                        v[i - 1] += 1;
                        v[i] = 3;
                    }
                    else
                        v[i] += m;
                }
                else
                {
                    cout << "\n";
                }
            }
        }
        int result = 0;
        for (int i = 0; i < ch; i++)
        {
            if (v[i] == 8)
                result++;
        }
        return result;
    }
};