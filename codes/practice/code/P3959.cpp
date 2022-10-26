#include<bits/stdc++.h>
using namespace std;
const int maxn = 12,INF = 2147483647;
int n,m,ans = INF;
bool vis[maxn],built[maxn][maxn];
int edges[maxn + 5][maxn + 5];
void dfs(int depth,int val,int pos){
  // printf("(%d,%d,%d)->",depth,val,pos);
  if(depth >= n + 1){
    ans = min(ans,val);
    return;
  }
  for(int i = 1;i <= n;i++){
    if(edges[pos][i] != INF && !built[pos][i] && !vis[i]){
      built[pos][i] = true;
      built[i][pos] = true;
      vis[i] = true;
      dfs(depth + 1,val + (edges[pos][i] * depth),i);
      vis[i] = false;
      built[pos][i] = false;
      built[i][pos] = false;
    }
  }
  return;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i = 0;i < maxn + 5;i++)
    for(int j = 0;j < maxn + 5;j++)
      edges[i][j] = INF;
  for(int i = 0;i < m;i++){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    edges[u][v] = min(edges[u][v],w);
    edges[v][u] = min(edges[v][u],w);
  }
  for(int i = 1;i <= n;i++){
    memset(vis,0,sizeof(vis));
    memset(built,0,sizeof(built));
    dfs(1,0,i);
    // printf("\n");
  }
  printf("%d\n",ans);
  return 0;
}
