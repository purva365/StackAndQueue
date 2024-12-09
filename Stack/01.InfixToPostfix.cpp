/*
tc=o(n)+o(n) for outer loop+ inner loop
    sc=o(n)+o(n) for store ele + store ans
    */


#include<iostream>
//#include<bits/stdc.h>
#include<stack>
using namespace std;
//for priority
int priority(char c)
{
    if(c=='+' || c=='-')return 1;
    if(c=='*' || c=='/')return 2;
    if(c=='^')return 3;
    return 0;
}
string infixtopostfix(string s)
{
    stack<char>st;
    string ans="";
    int n=s.length();
    for(int i=0;i<s.length();i++)
    {
       
            if((s[i]>='A' && s[i]<='Z')||
              (s[i]>='a' && s[i]<='z') ||
              (s[i]>='0' && s[i]<='9'))
              {
             ans+=s[i];
              }
              
           else if(s[i]=='(')
           {
               st.push(s[i]);
           }
           else if(s[i]==')')
           {
               while(!st.empty() && st.top()!='(')
               {
                   
                   ans+=st.top();
                   st.pop();
               }
               st.pop();
           }
            else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                 if(s[i] == '^' && st.top() == '^') break;
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
            } 
    }
    
      
    
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    
    return ans;
}


int main() {
    
    
    
 string s="(p+q)*(m-n)";
 cout<<"Infix expression: "<<s<<endl;
 string postfix = infixtopostfix(s);
 cout<<"postfix exp : = "<<postfix<<endl;
 
 
 
    return 0;
}
   
