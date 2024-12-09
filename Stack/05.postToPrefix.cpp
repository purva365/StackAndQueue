#include <bits/stdc++.h>
using namespace std;


string postfixtoprefix(string s) {
    stack<string> st; //use string not char
    for (int i =  0; i<s.length(); i++) {
     
        if (isalpha(s[i]) || isdigit(s[i])) { 
            st.push(string(1, s[i])); 
        }
         else { 
          
            string t1 = st.top(); 
            st.pop();
            string t2 = st.top();
            st.pop();
          
            string con =  s[i] + t2 + t1 ;
          
            st.push(con); 
        }
    }
    return st.top();
}

int main() {
    string s ="AB-DE+F*/";
    cout << "postfix: " << s << endl;
    cout << "prefix: " <<postfixtoprefix(s) << endl; 
}
