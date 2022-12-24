#define ll long long int
class Solution {
public:
    int K = 1e9+7;
    int numTilings(int n) {
        vector<ll> dp(1001);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(n<=3) return dp[n];
        for(int i=4;i<=n;++i){
            dp[i]=2*dp[i-1]+dp[i-3]; 
            dp[i]%=K;
        }
        return dp[n];
    }
};