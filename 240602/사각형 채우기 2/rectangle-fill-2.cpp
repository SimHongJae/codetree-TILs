#include <iostream>

using namespace std;
int main() {
    int n;
    int arr[1005];
    arr[1]=1;
    arr[2]=3;

    cin>>n;
    for(int i=3;i<=n;i++){
        arr[i] = arr[i-1] + 2*arr[i-2];
    }
    cout<<arr[n];
    return 0;
}