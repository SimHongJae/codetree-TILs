#include <iostream>
#include <math.h>

using namespace std;
int main() {
    
    int a,b;
    cin>>a>>b;

    if(a<b){
        int lg = (int)ceil(log(b-a)/log(4));
        int ans=0;
        for(int i=0;i<lg;i++){
            ans+=6*pow(4,i);
        }
        ans+=b-a;
        cout<<ans;
    }
    else{
        int lg = (int)ceil(log((a-b)*2)/log(4));
        //cout<<lg;
        
        int ans=0;
        for(int i=0;i<lg-1;i++){
            ans+=6*pow(4,i);
        }
        ans += 2*pow(4,lg-1);
        ans += a-b;
        cout<<ans;
        
    }


    return 0;
}