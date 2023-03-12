class Solution {
public:
    int vowelStrings(vector<string> &w, int l, int r)
    {
        int ans = 0;
        for (int i = l; i <= r; i++)
        {
            int n = w[i].size();
            if ((w[i][0] == 'a' || w[i][0] == 'e' || w[i][0] == 'i' || w[i][0] == 'o' || w[i][0] == 'u') && (w[i][n - 1] == 'a' || w[i][n - 1] == 'e' || w[i][n - 1] == 'i' || w[i][n - 1] == 'o' || w[i][n - 1] == 'u'))
                ans++;
        }
        return ans;
    }
};