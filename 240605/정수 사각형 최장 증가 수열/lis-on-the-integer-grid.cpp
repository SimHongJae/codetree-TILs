#include <bits/stdc++.h>

using namespace std;

typedef struct Point{
    int x;
    int y;
}PT;

typedef struct Point2{
    int x;
    int y;
    int arr;
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
int arr[505][505];
int ans[505][505];
PT2 arr2[250000];

int main() {
    int n;
   
    int max_num = 0;
    PT max_pt;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            arr2[n*i+j].arr = arr[i][j];
            arr2[n*i+j].x=i;
            arr2[n*i+j].y=j;
          
        }
    }

    sort(arr2,arr2+n*n,compare);

    
    
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

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


        
   
    
   int max_ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            max_ans = max(max_ans,ans[i][j]);
            
        }
    }

    printf("%d",max_ans);
    return 0;
}