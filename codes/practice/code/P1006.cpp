#include<bits/stdc++.h>
using namespace std;
long long val[120][60][60],w[60][60],m,n;
// void dfs(int depth,int value,bool ret,int nx,int ny);
int main(){
  scanf("%lld%lld",&m,&n);
  for(int i = 1;i <= m;i++)
    for(int j = 1;j <= n;j++)
      scanf("%lld",&w[i][j]);
  memset(val,-1,sizeof(val));
  val[2][1][1] = 0;
  for(int k = 3;k < m + n;k++)
    for(int i1 = 1;i1 < n;i1++)
      for(int i2 = i1 + 1;i2 <= n;i2++){
        long long s = val[k][i1][i2];
        s = max(val[k - 1][i1][i2],s);
        s = max(val[k - 1][i1 - 1][i2],s);
        s = max(val[k - 1][i1][i2 - 1],s);
        s = max(val[k - 1][i1 - 1][i2 - 1],s);
        if(s == -1) continue;
        val[k][i1][i2] = s + w[k-i1][i1] + w[k - i2][i2];
      }
  // dfs(0,0,false,1,1);
  printf("%lld\n",val[m + n - 1][n - 1][n]);
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
