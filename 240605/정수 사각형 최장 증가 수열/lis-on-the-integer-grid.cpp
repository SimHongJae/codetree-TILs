#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
    long long int x;
    long long int y;
}PT;

typedef struct Point2{
    long long int x;
    long long int y;
    long long int arr;
}PT2;

int compare(PT2 a, PT2 b){
    if(a.arr == b.arr){
        if(a.x == b.x){
            return a.y<b.y;
        }
        return a.x<b.x;
    }
    return a.arr<b.arr;
}
long long int arr[1000][1000];
long long int ans[1000][1000];
PT2 arr2[1000000];

int main() {
    long long int n;
   
    long long int max_num = 0;
    PT max_pt;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            arr2[n*i+j].arr = arr[i][j];
            arr2[n*i+j].x=i;
            arr2[n*i+j].y=j;
          
        }
    }

    sort(arr2,arr2+n*n,compare);

    
    
    long long int dx[4]={1,-1,0,0};
    long long int dy[4]={0,0,1,-1};

    queue<PT> q;
    for(int i=0;i<n*n;i++){
        PT pt;
        pt.x = arr2[i].x;
        pt.y = arr2[i].y;
        q.push(pt);
    }
    




    while(!q.empty()){
            PT a = q.front();
            q.pop();
            if(ans[a.x][a.y]==0)ans[a.x][a.y]=1;
            for(int i=0;i<4;i++){

                PT next;
                next.x = a.x+dx[i];
                next.y = a.y+dy[i];
                if(next.x<0)continue;
                if(next.y<0)continue;
                if(next.x>=n)continue;
                if(next.y>=n)continue;

                if(arr[a.x][a.y]>arr[next.x][next.y]){
                    if(ans[next.x][next.y]<=ans[a.x][a.y]+1){
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