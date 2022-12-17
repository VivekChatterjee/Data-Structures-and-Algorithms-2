class Solution {
public:
    // USING TOPO SORT
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ing, vector<string>& sup) {
        int n = recipes.size();
        unordered_map<string, vector<string>> rel;
        unordered_map<string, int>indegree;
        // recipe is pointing to ingredients but in this prob we've to reverse the edges
        // so ingredients are pointing towards recipes
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<ing[i].size(); j++)
            {
                rel[ing[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        vector<string>ans;
        for(string s: sup) q.push(s);
        while(!q.empty())
        {
            string f = q.front();
            q.pop();
            for(auto i: rel[f])
            {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(indegree[recipes[i]] == 0) ans.push_back(recipes[i]);
        }
        return ans;
    }
};