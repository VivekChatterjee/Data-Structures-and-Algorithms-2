class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>s;
        int i=0,j=0;
        //i at pushed, j at popped
        while(j<n)
        {
            if(!s.empty() && s.top() == popped[j])
            {
                s.pop();
                j++;
            }
            else if(i<n)
            {
                s.push(pushed[i]);
                i++;
            }
            else break;
        }
        return s.empty();
    }
};