#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    //check Operator
    return (!isalpha(c) && !isdigit(c));
}

int Priority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string infixToPostfix(string s) {
    s = '(' + s+  ')';
    int n = s.size();
    stack<char> st;
    string ans;

    for (int i = 0; i < n; i++) {
        // If the scanned character is an operand, add it to output.
        if (isalpha(s[i]) || isdigit(s[i])) {
            ans += s[i];
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (s[i] == '(') {
            st.push('(');
        }
        // If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
        else if (s[i] == ')') {
            while ( st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            // Remove '(' from the stack
            
                st.pop();
            
        }
        // Operator found
       else {
      if (isOperator(st.top())) {
        if (s[i] == '^') {
          while (Priority(s[i]) <= Priority(st.top())) {
            ans += st.top();
            st.pop();
          }

        } else {
          while (Priority(s[i]) < Priority(st.top())) {
           ans += st.top();
            st.pop();
          }

        }

        // Push current Operator on stack
        st.push(s[i]);
      }
    }
  }
    
    while (!st.empty()) {
      ans += st.top();
        st.pop();
    }
    
    return ans;
}

string infixToPrefix(string s) {
    int n= s.size();

    // Reverse infix
    reverse(s.begin(), s.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    string prefix = infixToPostfix(s);

    // Reverse postfix to get prefix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string s = ("x+y*z/w+u");
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << infixToPrefix(s) << endl;
    return 0;
}
