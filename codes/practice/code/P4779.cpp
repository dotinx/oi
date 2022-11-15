#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n,m,s;
// int dis[MAXN],h[MAXN],to[MAXN],val[MAXN],nxt[MAXN];
int dis[MAXN];
struct edge{
    int v,w;
};
vector<edge> edges[MAXN];
bool vis[MAXN];
void add(int u,int v,int w){
    edges[u].push_back((edge){v,w});
}
void Dijkstra(){
    memset(dis,0x3F,sizeof(dis));
    queue<pair<int,int> > q;
    dis[s] = 0;
    q.push(make_pair(-0,s)); //-dis v
    while(!q.empty()){
        // int u = 0;
        // for(int i = 1;i <= n;i++){
        //     if(!vis[i] && dis[u] > dis[i]){
        //         u = i;
        //     }
        // }
        // if (u == 0) break;
        // vis[u] = true;
        // for(int i = h[u];i ;i = nxt[i]){
        //     if(dis[to[i]] > (long long)dis[u] + val[i]){
        //         dis[to[i]] = dis[u] + val[i];
        //     }
        // }
        // 你老老实实存边不香吗？？？
        int u = q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto ed : edges[u]){
            int v = ed.v,w = ed.w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push(make_pair(-dis[v],v));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for(int i = 1,u,v,w;i <= m;i++){
        cin >> u >> v >> w;
        add(u,v,w);
    }
    Dijkstra();
    for(int i = 1;i <= n;i++){
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}