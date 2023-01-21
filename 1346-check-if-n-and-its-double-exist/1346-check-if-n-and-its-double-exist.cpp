class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, int>m;
        for(int i: arr) m[i]++;
        for(int i: arr)
        {
            if(i != 0 && m.count(2*i)) return 1;
            else if(i==0)
            {
                if(m[0] > 1) return 1;
            }
        }
        return 0;
    }
};