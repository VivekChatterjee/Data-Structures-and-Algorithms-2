// find all combinations of given numbers
// class Solution {
// public:
//     vector<vector<int>>ans;
//     void find(int total, int sum, int k, int n, vector<int>v2, unordered_map<int, int>m)
//     {
//         if(sum > n) return;
//         else if(total == k)
//         {
//             if(sum == n)
//             {
//                 ans.push_back(v2);                
//                 return;
//             }
//             else return;
//         }
//         for(int i=1; i<=9; i++)
//         {
//             if(!m.count(i))
//             {
//                 v2.push_back(i);
//                 m[i]++;
//                 find(total+1, sum+i, k, n, v2, m);
//                 v2.pop_back();
//                 m[i]--;
//                 if(m[i] == 0) m.erase(i);
//             }
//         }
//     }
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<int>v, v2;
//         unordered_map<int, int>m;
//         find(0, 0, k, n, v2, m);
//         return ans;        
//     }
// };





#define vc vector
class Solution {
public:
    vc<vc<int>>ans;
    void find(int num, int total, int sum, int k, int n, vector<int>v)
    {
        if(total == k)
        {
            if(sum == n)
            {
                ans.push_back(v);
                return;
            }
            else return;
        }
        else if(sum > n || num > 9) return;
        v.push_back(num);
        find(num+1, total+1, sum+num, k, n, v);
        v.pop_back();
        
        // dont take
        find(num+1, total, sum, k, n, v);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        find(1, 0, 0, k, n, v);
        return ans;
    }
};