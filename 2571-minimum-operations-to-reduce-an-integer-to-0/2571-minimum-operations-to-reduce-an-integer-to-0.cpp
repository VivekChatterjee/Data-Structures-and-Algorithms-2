#define ll long long
class Solution {
public:
    int highestPow(int x)
    {
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        return x ^ (x >> 1);
    }
    int lowestPow(int n)
    {
        ll a = log2(n);
        if (pow(2, a) == n)
            return n;
        return (pow(2, a + 1));
    }
    int oper(int n)
    {
        bool neg = 0;
        if(n==0) return 0;
        if (n < 0)
        {
            neg = 1;
            n = abs(n);
        }
        int high = highestPow(n);
        int low = lowestPow(n);
        int ct = 0;
        if (abs(high - n) < abs(n - low))
        {
            if (neg)
            {
                ct = 1 + oper(-n + high);
            }
            else
            {
                ct = 1 + oper(n - high);
            }
        }
        else
        {
            if (neg)
            {
                ct = 1 + oper(-n + low);
            }
            else
            {
                ct = 1 + oper(n - low);
            }
        }
        return ct;
    }
    int minOperations(int n)
    {
        return oper(n);
    }
};