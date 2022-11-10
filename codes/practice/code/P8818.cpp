#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 2500 + 1;
int n,m,k;
int w[maxn],dis[maxn];
bool vis[maxn];
vector<int> edges[maxn];
bool conn[maxn][maxn];
void addedge(int u,int v){
  edges[u].push_back(v);
  conn[u][v] = 1;
}
void dijkstra(){
  memset(vis,0,sizeof(vis));
  memset(dis,0x7f,sizeof(dis));
  queue<pair<int,int> > q;
  q.push(make_pair(0,1));
  dis[1] = 0;
  while (!q.empty()) {
    int u = q.front().second;q.pop();
    if(vis[u]) continue;
    vis[u] = true;
    for(auto ed:edges[u]){
      int v = ed;
      if(dis[v] > dis[u] + 1){
        dis[v] = dis[u] + 1;
        q.push(make_pair(-dis[v],v));
      }
    }
  }
}
void bfs(){
  queue<pair<pair<int,int>,pair<int,int> > q;
  q.push(make_pair(make_pair(1,0),make_pair(0,0)));
  while(!q.empty()){
    auto that = q.front();q.pop();
    int i1 = that.first.first,
      i2 = that.first.second,
      i3 = that.second.first,
      i4 = that.second.second;
    if(i1 != 0 && i2 != 0 && i3 != 0 && i4 != 0){
      if(conn[i4][i1]){
        ans = max(ans,w[i1] + w[wi2] + w[i3] + w[i4]);
      }
    }else{
      if(i2 == 0 && dis[i2] <= k){
        for()
        q.push(make_pair(make_pair(i1,0),make_pair(0,0)));
      }
    }
  }
}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  for(int i = 2;i <= n;i++){
    scanf("%d",&w[i]);
  }
  for(int i = 0;i < n;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    addedge(u,v);
    addedge(v,u);
  }
  dijkstra();
  for(int i = 0;i <= n + 1;i++){
    printf("%d ",dis[i]);
  }
  return 0;
}
