#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(int arr[], int n) {
    vector<int> nge(n, -1); // Initialize NGE array with -1
    stack<int> st;

    // Iterate from 2n - 1 to 0 for simulating the circular nature of the array
    for (int i = 2 * n - 1; i >= 0; i--) {
        // While the stack is not empty and the top of the stack is less than or equal to current element
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();  // Pop elements from the stack
        }

        // Only process the first n elements (i < n)
        if (i < n) {
            if (!st.empty()) {
                nge[i] = st.top();  // The top of the stack is the next greater element
            }
            st.push(arr[i % n]);  // Push the current element to the stack
        }
    }

    return nge;  // Return the NGE array
}

int main() {
    int arr[] = {4, 5, 1, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Get next greater elements
    vector<int> nge = nextGreaterElement(arr, n);

    // Print the next greater elements
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}
