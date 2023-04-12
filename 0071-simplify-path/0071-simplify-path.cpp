class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string p;

        while (getline(ss, p, '/')) {
            if (p == ".." && !s.empty()) s.pop();
            else if (p != "" && p != "." && p != "..") s.push(p);
        }

        if (s.empty()) return "/";

        string res;
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res;
    }
};