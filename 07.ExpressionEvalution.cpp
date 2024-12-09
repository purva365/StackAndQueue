#include <iostream>
#include <stack>
#include <cctype>
#include <cmath> // For pow function
using namespace std;

// Function to determine operator precedence
int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Step 1: Infix to Postfix Conversion
string infixtopostfix(string s) {
    stack<char> st;
    string ans = "";

    for (char c : s) {
        if (isdigit(c)) { // If it's a number
            ans += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop the '('
        } else { // Operator
            while (!st.empty() && priority(c) <= priority(st.top())) {
                if (c == '^' && st.top() == '^') break; // Right-associative for '^'
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Append remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// Step 2: Evaluate Postfix Expression
int evaluatepostfix(string postfix) {
    stack<int> st;
    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0'); // Convert char to int
        } else {
            int val2 = st.top(); // Top is the second operand
            st.pop();
            int val1 = st.top(); // Below top is the first operand
            st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top(); // Final result
}

int main() {
    string infix = "(5*2)+1";
    cout << "Infix Expression: " << infix << endl;

    string postfix = infixtopostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatepostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
