class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // smallest power of 2 greater than or equal to "label" concept
        int level = log2(label) + 1;
        vector<vector<int>>tree(level);
        int numb = 1, numbers = 1, last = 0, ind, nums;
        for(int i=1; i<=level; i++)
        {
            nums = numbers;
            tree[i-1].resize(numbers);
            if(i % 2 != 0)
            {
                ind = 0;
                while(nums--)
                {
                    tree[i-1][ind++] = numb++;
                }
            }
            else
            {
                ind = numbers-1;
                while(nums--)
                {
                    tree[i-1][ind--] = numb++;
                }
            }
            numbers*=2;
            
        }
        unordered_map<int, int>par;
        par[tree[0][0]] = -1;
        for(int i=1; i<tree.size(); i++)
        {
            int ind = 0;
            for(int j=0; j<tree[i].size(); j++)
            {
                par[tree[i][j]] = tree[i-1][ind];
                if(j % 2 != 0) ind++;
            }
        }
        int lab = label;
        vector<int>ans;
        ans.push_back(lab);
        while(par[lab] != -1)
        {
            ans.push_back(par[lab]);
            lab = par[lab];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};