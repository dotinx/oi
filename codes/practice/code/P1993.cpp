#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

int n,m;

struct edge{
  int v,w;
};
vector<edge> e[MAXN];
int dis[MAXN],cnt[MAXN];
bool vis[MAXN];
queue<int> q;

bool spfa(int s){
  memset(dis,0x7F,sizeof(dis));
  dis[s] = 0;vis[s] = 1;
  q.push(s);
  while(! q.empty()){
    int u = q.front();q.pop();
    vis[u] = 0;
    for(auto ed : e[u]){
      int v = ed.v,w = ed.w;
      if(dis[v] > dis[u] + w){
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;
        if(cnt[v] >= n) return false;
        if(!vis[v]) q.push(v),vis[v] = 1;
      }
    }
  }
  return true;
}
void addedge(int u,int v,int w){
  e[u].push_back((edge){v,w});
  return;
}

int main(){
  scanf("%d%d",&n,&m);
  while(m--){
    int type,a,b,c;
    scanf("%d%d%d",&type,&a,&b);
    if(type == 1){
      scanf("%d",&c);
      addedge(a,b,-c);
    }else if(type == 2){
      scanf("%d",&c);
      addedge(b,a,c);
    }else{
      addedge(a,b,0);
      addedge(b,a,0);
    }
  }
  for(int i = 1 ;i <= n;i++){
    addedge(n + 1,i,0);
  }
  if(spfa(n + 1))
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
