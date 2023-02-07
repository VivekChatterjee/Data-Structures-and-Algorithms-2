#define ll long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<3) return 1;
        ll s=1, e=sqrt(c);
        while(s<=e)
        {
            ll a=s*s;
            ll b=e*e;
            if(a==c || b==c || a+b==c) return 1;
            else if(a+b>c) e--;
            else s++;
        }
        return 0;
    }
};