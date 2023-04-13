class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>s;
        int i=0, j=0;
        while(i<n)
        {
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[j])
            {
                s.pop();
                j++;
            }
            i++;
        }
        return s.empty();
    }
};