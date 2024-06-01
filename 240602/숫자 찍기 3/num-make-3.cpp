#include <iostream>

using namespace std;
int pas[100][100];

void print1(int a){
    
    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            cout<<pas[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void print2(int a){
    for(int i=a;i>=1;i--){
        for(int j=0;j<a-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<pas[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void print3(int a){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            cout<<pas[a-j+1][i-j+1]<<" ";
        }
        cout<<"\n";
    }
}
int main() {
    int a,b;
    cin>>a>>b;

    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            if(j==1 || j==i )pas[i][j]=1;
            else{
                pas[i][j] = pas[i-1][j-1]+pas[i-1][j];
            }   
        }
    }

    if(b==1)print1(a);
    if(b==2)print2(a);
    if(b==3)print3(a);
    return 0;
}