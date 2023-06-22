#include <bits/stdc++.h>
using namespace std; 
bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == '}') {
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i] == ']') {
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return st.empty();
}