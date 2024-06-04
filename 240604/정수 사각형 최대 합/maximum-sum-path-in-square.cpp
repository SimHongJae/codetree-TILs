#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int arr[105][105];
    int ans[105][105];

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                ans[i][j] = arr[i][j];
                continue;
            }
            if(i==0){
                ans[i][j] = ans[i][j-1]+arr[i][j];
                continue;
            }
            if(j==0){
                ans[i][j] = ans[i-1][j]+arr[i][j];
                continue;
            }
            ans[i][j] = max(ans[i-1][j],ans[i][j-1]) + arr[i][j];
        }
    }
    cout<<ans[n-1][n-1];
    return 0;
}