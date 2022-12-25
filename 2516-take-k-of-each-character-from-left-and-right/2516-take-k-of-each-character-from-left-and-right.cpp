class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char, int>m, m2;
        for(auto c: s) m[c]++;
        if(m['a'] < k || m['b'] < k || m['c'] < k) return -1;
        int window = 0, j = 0, ans = n;
        for(int i=0; i<n; i++)
        {
            m[s[i]]--;
            window++;
            while(m[s[i]] < k)
            {
                m[s[j++]]++;
                window--;
            }
            ans = min(ans, n - window);
        }
        return ans;
    }
};