#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidSubstring(string s) {
        stack<int> st;
        st.push(-1);

        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') st.push(i);
            else {
                st.pop();
                if(st.empty()) st.push(i);
                else ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;

    cout << sol.longestValidSubstring("(()") << endl;   // output -> 2
    cout << sol.longestValidSubstring(")()())") << endl;   // output -> 4
    cout << sol.longestValidSubstring("") << endl;       // output -> 0
}