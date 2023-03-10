class Solution {
public:
    int passThePillow(int n, int time)
    {
        int i = 0, in = 0;
        bool front = 1, changed=0;
        while (time >= 0)
        {
            in = i + 1;
            if (!time)
                return in;
            if (i == n - 1 || (!front && i == 0))
            {
                front = !front;
            }
            if (front)
            {
                i++;
            }
            else
                i--;
            time--;
        }
        return in;
    }
};