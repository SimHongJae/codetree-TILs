#include <iostream>
using namespace std;

int main() {
    int n;
    int st[1005];
    cin>>n;
    st[1]=0;
    st[2]=1;
    st[3]=1;
    for(int i=4;i<=n;i++){
        st[i] = st[i-2]+st[i-3];
        st[i]%=10007;
    }    
    cout<<st[n];
    return 0;
}