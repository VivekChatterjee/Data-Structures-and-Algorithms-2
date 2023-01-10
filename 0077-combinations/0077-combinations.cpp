// class Solution {
// public:
//     vector<vector<int>>ans;
//     void comb(int num, int n, int k, vector<int>v)
//     {
//         if(num>n || v.size()==k)
//         {
//             if(v.size() == k) ans.push_back(v);
//             return;
//         }
//         // dont
//         comb(num+1, n, k, v);
//         // take
//         v.push_back(num);
//         comb(num+1, n, k, v);
//         // for(int i=num; i<=n; i++)
//         // {
//         //     v.push_back(i);
//         //     comb(i+1, n, k, v);  
//         //     v.pop_back();
//         // }
//     }
//     vector<vector<int>> combine(int n, int k) {
//         vector<int>v;
//         comb(1, n, k, v);
//         return ans;
//     }
// };


class Solution {
public:
    void fn(int i,int k,int n,vector<int>&nums,vector<int>&v,
        vector<vector<int>>&ans){
		
		//base case
        if(i>n || k==0){
            if(k==0)
                ans.push_back(v);
            return;
        }
		
		//pick up the element
        v.push_back(nums[i]);
        fn(i+1,k-1,n,nums,v,ans);
        v.pop_back();
        
		//dont pick up the element
        fn(i+1,k,n,nums,v,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v,nums(n+1,0);
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            nums[i]=i;
        }
        fn(1,k,n,nums,v,ans);
        return ans;
    }
};