class Solution {
public:
    vector<int> evenOddBit(int n) {
        bool ev=1;
        int even=0, odd=0;
        while(n>0)
        {
            if(ev)
            {
                if(n&1) even++;
            }
            else
            {
                if(n&1) odd++;
            }
            ev=!ev;
            n=n>>1;
        }
        return {even, odd};
    }
};