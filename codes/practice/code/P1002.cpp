#include<bits/stdc++.h>
using namespace std;
int a[25][25],n,m,j,k,ans = 0;
void dfs(int x,int y){
  if(x == n && y == m){
    ans++;
    return;
  }
  if(x < n && !a[x + 1][y]) dfs(x + 1,y);
  if(y < m && !a[x][y + 1]) dfs(x,y + 1);
  return;
}
int main(){
  scanf("%d%d%d%d",&n,&m,&j,&k);
  memset(a,0,sizeof(a));
  a[j][k] = 1;
  if(j + 2 < n && k - 1 > 0)a[j + 2][k - 1] = 1;
  if(j - 2 > 0 && k - 1 > 0)a[j - 2][k - 1] = 1;
  if(j + 1 < n && k - 2 > 0)a[j + 1][k - 2] = 1;
  if(j - 1 > 0 && k - 2 > 0)a[j - 1][k - 2] = 1;
  if(j + 2 < n && k + 1 < m)a[j + 2][k + 1] = 1;
  if(j - 2 > 0 && k + 1 < m)a[j - 2][k + 1] = 1;
  if(j + 1 < n && k + 2 < m)a[j + 1][k + 2] = 1;
  if(j - 1 > 0 && k + 2 < m)a[j - 1][k + 2] = 1;
  dfs(0,0);
  printf("%d\n",ans);
  return 0;
}
