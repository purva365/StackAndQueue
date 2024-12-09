#include <bits/stdc++.h>
using namespace std;


string Postfixtoinfix(string s) {
    stack<string> st; //use string not char
    for (int i = 0; i < s.length(); i++) {
     
        if (isalpha(s[i]) || isdigit(s[i])) { 
            st.push(string(1, s[i])); 
        }
         else { 
          
            string t1 = st.top(); 
            st.pop();
            string t2 = st.top();
            st.pop();
          
            string con = '(' + t2 + s[i] + t1 + ')';
            st.push(con); 
        }
    }
    return st.top();
}

int main() {
    string s = "ab*c+"; // Valid postfix expression
    cout << "Postfix: " << s << endl;
    cout << "Infix: " << Postfixtoinfix(s) << endl; 
    return 0;
}
