#include <bits/stdc++.h>
using namespace std;


string prefixtopostfix(string s) {
    stack<string> st; //use string not char
    for (int i =  s.length()-1; i>=0; i--) {
     
        if (isalpha(s[i]) || isdigit(s[i])) { 
            st.push(string(1, s[i])); 
        }
         else { 
          
            string t1 = st.top(); 
            st.pop();
            string t2 = st.top();
            st.pop();
          
            string con =   t1 + t2 +s[i] ;
          
            st.push(con); 
        }
    }
    return st.top();
}

int main() {
    string s ="/-AB*+DEF";
    cout << "prefix: " << s << endl;
    cout << "postfix: " << prefixtopostfix(s) << endl; 
}
