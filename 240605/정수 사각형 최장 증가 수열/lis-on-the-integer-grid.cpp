#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
    int x;
    int y;
}PT;

long long int arr[1000][1000];
long long int ans[1000][1000];


int main() {
    long long int n;
   
    long long int max_num = 0;
    PT max_pt;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            max_num = max(max_num,arr[i][j]);
            if(max_num == arr[i][j]){
                max_pt.x = i;
                max_pt.y = j;
            }
        }
    }
    ans[max_pt.x][max_pt.y] = 1;
    long long int dx[4]={1,-1,0,0};
    long long int dy[4]={0,0,1,-1};

    queue<PT> q;
    q.push(max_pt);
    while(!q.empty()){
        PT a = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            PT next;
            next.x = a.x+dx[i];
            next.y = a.y+dy[i];
            if(next.x<0)continue;
            if(next.y<0)continue;
            if(next.x>=n)continue;
            if(next.y>=n)continue;

            if(arr[a.x][a.y]>arr[next.x][next.y]){
                if(ans[next.x][next.y]<ans[a.x][a.y]+1){
                    q.push(next);
                    ans[next.x][next.y] = ans[a.x][a.y]+1;
                }
            }
        }
    }

   long long int max_ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            max_ans = max(max_ans,ans[i][j]);
            
        }
    }

    cout<<max_ans;
    return 0;
}