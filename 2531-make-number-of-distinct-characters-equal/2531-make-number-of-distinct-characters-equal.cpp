class Solution
{
public:
    bool isItPossible(string word1, string word2)
    {
        vector<int> v1(26), v2(26);
        for (char c : word1) v1[c - 'a']++;
        for (char c : word2) v2[c - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (v1[i] > 0 && v2[j] > 0)
                {
                    v1[i]--;
                    v2[j]--;
                    v2[i]++;
                    v1[j]++;
                    int cnt1 = 0, cnt2 = 0;
                    for (int k = 0; k < 26; k++)
                    {
                        if (v1[k] >= 1)
                            cnt1++;
                        if (v2[k] >= 1)
                            cnt2++;
                    }
                    if (cnt1 == cnt2) return 1;
                    v1[i]++;
                    v2[j]++;
                    v2[i]--;
                    v1[j]--;
                }
            }
        }
        return 0;
    }
};