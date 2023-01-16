#define ll long long int
class Solution {
public:
    const ll K=1e9+7;
    int countHomogenous(string s) {
        ll i=0, j=0, ans=0;
        unordered_map<char, ll>m;
        s+='#';
        ll n=s.size();
        while(j<n)
        {
            if(s[i] == s[j])
            {
                j++;
                continue;
            }
            ll size=j-i;
            ans+=(size * (size+1))/2;
            ans%=K;
            i=j;
        }
        return ans;
    }
};