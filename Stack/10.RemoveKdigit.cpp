#include <iostream>
#include <stack>
#include <string>
using namespace std;

string RemoveKDigits(int a[], int n, int k) {
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // Remove elements from stack if top is greater than current and k > 0
        while (!st.empty() && st.top() > a[i] && k > 0) {
            st.pop();
            k--;
        }
        st.push(a[i]);
    }

    // Remove remaining elements if k > 0
    while (!st.empty() && k > 0) {
        st.pop();
        k--;
    }

    // Convert stack to string
    string ans = "";
    while (!st.empty()) {
        ans = to_string(st.top()) + ans;
        st.pop();
    }

    // If result is empty, return "0"
    return ans.empty() ? "0" : ans;
}

int main() {
    int a[] = {1, 4, 3, 2, 2, 1, 9};
    int k = 3;
    int n = sizeof(a) / sizeof(a[0]);

    string ans = RemoveKDigits(a, n, k);
    cout << "Result after removing " << k << " digits: " << ans << endl;

    return 0;
}
