/*tc=o(2N) con str=o(n)+o(n)
sc=o(n)*/
#include <bits/stdc++.h>
using namespace std;

string prefixtoinfix(string s) {
    stack<string> st; // Use a stack to hold infix expressions
    // Reverse iterate over the prefix expression
    for (int i = s.length() - 1; i >= 0; i--) {
        // Skip spaces
        if (s[i] == ' ') continue;
        
        // Operands
        if (isalpha(s[i]) || isdigit(s[i])) { // Check for operands
            st.push(string(1, s[i])); // Push the operand as a string
        }
        // Operators
        else { // If the character is an operator
            // Pop the two top elements from the stack
            string t1 = st.top(); 
            st.pop();
            string t2 = st.top();
            st.pop();
            // Form the new infix expression
            string con = '(' + t1 + s[i] + t2 + ')';
            st.push(con); // Push the new expression back to the stack
        }
    }
    return st.top(); // Return the final infix expression
}

int main() {
    string s = "* + A B C"; // Valid prefix expression
    cout << "Prefix: " << s << endl;
    cout << "Infix: " << prefixtoinfix(s) << endl; 
    return 0;
}


