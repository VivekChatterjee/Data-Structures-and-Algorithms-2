#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<ll(ll, ll)>>m; // lambda function
        m = {
            { "+", [](ll a, ll b){ return a + b; } },
            { "-", [](ll a, ll b){ return a - b; } },
            { "*", [](ll a, ll b){ return a * b; } },
            { "/", [](ll a, ll b){ return a / b; } }
        };
        stack<ll>st;
        for(auto s: tokens)
        {
            if(!m.count(s)) st.push(stoll(s));
            else
            {
                ll num2 = st.top();
                st.pop();
                ll num1 = st.top();
                st.pop();
                st.push(m[s](num1, num2));
            }
        }
        return st.top();
    }
};