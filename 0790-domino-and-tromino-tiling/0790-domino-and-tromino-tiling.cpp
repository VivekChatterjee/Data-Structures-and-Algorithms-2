#define ll long long int
class Solution {
public:
    int K = 1e9+7;
    int numTilings(int n) {
        vector<ll> v(1001);
        v[1]=1;
        v[2]=2;
        v[3]=5;
        if(n<=3)
            return v[n];
        for(int i=4;i<=n;++i){
            v[i]=2*v[i-1]+v[i-3]; 
            v[i]%=K;
        }
        return v[n];
    }
};