#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    long long int a[1005],b[1005];
    a[0]=1;
    a[1]=2;
    a[2]=7;
    b[0]=1;
    b[1]=3;
    b[2]=10;
    for(int i=3;i<=n;i++){
        a[i] = 2*b[i-1]+a[i-2];
        b[i] = b[i-1] + a[i];

        a[i]%=1000000007;
        b[i]%=1000000007;
    }
    cout<<a[n];
    return 0;
}