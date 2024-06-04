#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long int arr[30]={0,};
    cin>>n;
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            arr[i]+=arr[j]*arr[i-1-j];
        }
    }
    cout<<arr[n];
    return 0;
}