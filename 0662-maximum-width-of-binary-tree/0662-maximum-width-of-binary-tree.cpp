#define ll long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>>q;
        q.push({root,0});
        ll ans=0;
        while(!q.empty())
        {
            ll n=q.size();
            ll mini=q.front().second;
            ll first,last;
            for(ll i=0;i<n;i++)
            {
                TreeNode* node=q.front().first;
                ll ind = q.front().second - mini;
                q.pop();
                if(i==0) first=ind;
                if(i==n-1) last=ind;
                
                ll lInd, rInd;
                if(node->left)
                    q.push({node->left, ((ll)(2*ind)+1)});
                if(node->right)
                    q.push({node->right,( (ll)(2*ind)+2)});
            }
            ans=max(ans, last-first + 1);
        }
        return ans;
    }
};