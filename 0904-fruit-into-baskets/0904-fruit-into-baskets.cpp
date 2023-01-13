class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>m;
        int n=fruits.size(), i=0, j=0, ans=0;
        while(j<n)
        {
            m[fruits[j]]++;
            while(m.size() > 2)
            {
                m[fruits[i]]--;
                if(m[fruits[i]] == 0) m.erase(fruits[i]);
                i++;
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};