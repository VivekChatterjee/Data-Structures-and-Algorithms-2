class Solution {
public:
    void dfs(string rec, unordered_map<string, int>&index, unordered_map<string, int>&present, vector<vector<string>>& ingredients)
    {
        present[rec] = 2;
        for(auto i: ingredients[index[rec]])
        {
            if(!present.count(i) && !index.count(i))
            {
                present[i] = 2;
                return;
            }
            else if(!present.count(i))
            {
                dfs(i, index, present, ingredients);
                if(present[i] == 2) return;
            }
            else if(present[i] == 2)  return;
        }
        present[rec] = 1;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string>ans;
        unordered_map<string, int> index, present;
        for(int i=0; i<n; i++) index[recipes[i]] = i;
        for(auto i: supplies) present[i] = 1;
        for(auto i: recipes)
        {
            if(!present.count(i))
            {
                dfs(i, index, present, ingredients);
            }
            if(present[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};