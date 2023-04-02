#define ll long long
class Solution
{
public:
    long long makeSubKSumEqual(vector<int> &a, int k)
    {
        int n = a.size();
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            // finding elements in same group
            vector<int> group;
            for (int j = i; a[j] != 0; j = (j+k)%n) {
                group.push_back(a[j]);
                a[j] = 0;
            }
            // median of that group
            if (group.size() > 0) {
                sort(group.begin(), group.end());
                int median = group[group.size() / 2];
                // make all elements equal to median for minimum cost
                for (auto &x: group) {
                    ans += abs(x - median);
                }
            }
        }
        return ans;
    }
};