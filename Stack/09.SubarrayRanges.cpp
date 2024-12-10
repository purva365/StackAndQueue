#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int subaraay(int arr[], int n) {
    int sum=0;
 for(int i=0;i<n;i++)
 {
     int largest=arr[i];
     int smallest=arr[i];
     for(int j=i+1;j<n;j++)
     {
         largest=max(largest,arr[j]);
         smallest=min(smallest,arr[j]);
         sum=sum+(largest-smallest);
     }
 }
 return sum;
}

int main() {
    int arr[] = {1,4,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans=subaraay(arr,n);
    cout<<ans;

    return 0;
}
