#include<bits/stdc++.h>
using namespace std;
int n,m,ans = 0,ans_dis = 0;
struct edge{
  int v,w;
  friend bool operator<(const edge a,const edge b){
    return a.w < b.w;
  }
};
vector<edge> edges[50100];
bool vis[50100];
void solve(int x){
  int max_m = 0,cnt = 0,dis = 0;
  memset(vis,0,sizeof(vis));
  priority_queue<edge> q;
  q.push({x,0});
  while(!q.empty()){
    if(cnt > m) break;
    edge top = q.top();q.pop();
    int u = top.v;
    if(vis[u]) continue;
    dis = max(dis,top.w);
    cnt++;
    vis[u] = true;
    for(auto ed : edges[u]){
      max_m = max(max_m,ed.w);
      q.push((edge){ed.v,ed.w + top.w});
    }
  }
  // printf("%d ",dis);
  if(cnt == m + 1 && max_m > ans_dis){
    ans_dis = max_m;
    ans = max(ans,dis);
  }
  return;
}
void addedge(int u,int v,int w){
  edges[u].push_back((edge){v,w});
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i = 0;i < n - 1;i++){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    addedge(u,v,w);
    addedge(v,u,w);
  }
  for(int i = 1;i <= n;i++){
    solve(i);
  }
  // printf("\n");
  printf("%d\n",ans);
  return 0;
}
