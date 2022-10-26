#include<bits/stdc++.h>
using namespace std;
int val[52][52][52][52],w[52][52],m,n;
long long ans = -1,cnt = 0;
// void dfs(int depth,int value,bool ret,int nx,int ny);
int main(){
  scanf("%d%d",&m,&n);
  for(int y = 1;y <= n;y++)
    for(int x = 1;x <= m;x++)
      scanf("%d",&w[x][y]);
  for(int y = n;y >= 1;y--){
    for(int x = m;x >= 1;x--){
      for(int yr = 1;yr <= n;yr++){
        for(int xr = 1;xr <= m;xr++){
          if(x == zr && y == yr) val[x][y][xr][yr] = 0;
          val[x][y][xr][yr] = max(val[x][y][xr + 1][yr],max(val[x][y][xr][yr+1],max()))
        }
      }
    }
  }
  dfs(0,0,false,1,1);
  printf("%lld\n%lld",ans,cnt);
  return 0;
}
// void dfs(int depth,int value,bool ret,int nx,int ny){
//   cnt++;
//   if(nx == 1 && ny == 1 && ret){
//     ans = max((long long)value,ans);
//     return;
//   }
//   int vthis = val[nx][ny];
//   if(nx == m && nx == n && !ret){
//     ret = true;
//   }
//   if(!ret){
//     if(nx != m){
//       val[nx][ny] = 0;
//       dfs(depth + 1,value + vthis,ret,nx + 1,ny);
//       val[nx][ny] = vthis;
//     }
//     if(ny != n){
//       val[nx][ny] = 0;
//       dfs(depth + 1,value + vthis,ret,nx,ny + 1);
//       val[nx][ny] = vthis;
//     }
//   }else{
//     if(nx != 1){
//       val[nx][ny] = 0;
//       dfs(depth + 1,value + vthis,ret,nx - 1,ny);
//       val[nx][ny] = vthis;
//     }
//     if(ny != 1){
//       val[nx][ny] = 0;
//       dfs(depth + 1,value + vthis,ret,nx,ny - 1);
//       val[nx][ny] = vthis;
//     }
//   }
// }
