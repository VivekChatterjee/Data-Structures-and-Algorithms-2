#define ll long long int
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<3) return 1;
        ll s=0, e=sqrt(c);
        while(s<e)
        {
            ll st=s*s, en=e*e;
            if(2*st == c || 2*en == c || en == (c-st)) return 1;
            else if(st + en < c) s++;
            else e--;
        }
        return 0;
    }
};