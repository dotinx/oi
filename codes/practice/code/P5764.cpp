#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000;
const int MAXM = 100000;

int n,m,ans = 2147483647;
int spot[7],b[10];

int dis[7][MAXN];
bool vis[MAXN];
struct edge{
  int v,w;
};
vector<edge> edges[MAXN];
void dijkstra(int t) {
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	memset(dis[t],0x7f,sizeof(dis[t]));
	memset(vis,0,sizeof(vis));
	dis[t][spot[t]]=0;
	q.push(make_pair(0,spot[t]));
	while(!q.empty()) {
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ed : edges[u]) {
      int v = ed.v,w = ed.w;
			if(dis[t][u]+w<dis[t][v]) {
				dis[t][v]=dis[t][u]+w;
				if(!vis[v]) {
					q.push(make_pair(dis[t][v],v));
				}
			}
		}
	}
}
void addedge(int u,int v,int w){
  edges[u].push_back((edge){v,w});
  return;
}
int sum;

void dfs(int t,int fa) {
	if(t>5){
		ans = min(ans,sum);
		return ;
	}
	for(int i=2; i<=6; i++) {
		if(vis[i]) continue;
		vis[i]=1;
		sum+=dis[fa][spot[i]];
		dfs(t+1,i);
		sum-=dis[fa][spot[i]];
		vis[i]=0;
	}
}

int main(){
    scanf("%d%d",&n,&m);
    // scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    for(int i = 2;i <= 6;i++){
      scanf("%d",&spot[i]);
    }
    spot[1] = 1;
    for(int i = 0;i < m;i++){
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      addedge(u,v,w);
      addedge(v,u,w);
    }
    for(int i = 1;i <= 6;i++){
      dijkstra(i);
      for(int j = 1;j <= n;j++){
        // printf("%d ",dis[i][j]);
      }
      // printf("\n");
    }

    memset(vis,0,sizeof(vis));
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}
