#define ll long long int
class Solution {
public:
    const ll K=1e9+7;
    int countHomogenous(string s) {
        ll n=s.size();
        ll i=0, j=0, ans=0;
        unordered_map<char, ll>m;
        s+='#';
        while(j<n)
        {
            while(s[i] == s[j])
            {
                j++;
            }
            ll size=j-i;
            ans+=(size * (size+1))/2;
            ans%=K;
            i=j;
        }
        return ans;
    }
};