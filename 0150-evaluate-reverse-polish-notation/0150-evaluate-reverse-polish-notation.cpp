#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i = 1;
        stack<ll>s;
        s.push(stoll(tokens[0]));
        while(!s.empty() && i < tokens.size())
        {
            char exp = tokens[i][0];
            if(tokens[i].size() == 1 &&  (exp == '*' || exp == '+' || exp == '/' || exp == '-'))
            {
                ll num1 = 1e5, num2 = 1e5, total = 0;
                while(total < 2)
                {
                    if(num2 == 1e5) num2 = s.top();
                    else num1 = s.top();
                    s.pop();
                    total++;
                }
                if(exp == '*')
                {
                    s.push(num1 * num2);
                }
                else if(exp == '+')
                {
                    s.push(num1 + num2);
                }
                else if(exp == '/')
                {
                    s.push(num1 / num2);
                }
                else
                {
                    s.push(num1 - num2);
                }
            }
            else s.push(stoi(tokens[i]));
            i++;
        }
        return s.top();
    }
};