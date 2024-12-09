#include<bits/stdc++.h>
using namespace std;
int pre(char s)
{
    if(s=='^')
    return 3;
else if(s=='*' || s=='/')
return 2;
else  if(s=='+' || s=='-')
return 1;
else
return 0;

}


string infixToPrefix(string s)
{
    stack<char>st;
string ans="";
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        //----------------------------------------
        if(s[i]>='A' && s[i]<='Z'||
        s[i]>='a' && s[i]<='z'||
        s[i]>='0' && s[i]<='9')
        {
           ans=ans+s[i];
        }
        //--------------------------------------------
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        //-------------------------------------------
       else if(s[i]==')')
       {
           while(st.top()!='(')
           {
               ans+=st.top();
               st.pop();
           }
           st.pop();
       }
       //---------------------------------------------
       else 
       {
           while(!st.empty()&& pre(s[i])<=pre(st.top()))
           {
               
                   if(s[i] == '^' && st.top() == '^') break; 
               ans+=st.top();
               st.pop();
           }
           st.push(s[i]);
       }
       //----------------------------------------------
    }  
           while(!st.empty())
           {
               ans+=st.top();
               st.pop();
           }
       
    return ans;
    }

int main()
{
    string s="a+b*(c^d-e)";
    cout<<"infixToPrefix"<<s<<endl;
    string postfix=infixToPrefix(s);
    cout<<"postfix exp : = "<<postfix<<endl;
 
    
    return 0;
}
