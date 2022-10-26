#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1010;
int t,n,r,h;
struct e{
  ll v,w;
  friend const bool operator<(const e a,const e b){
    return a.w < b.w;
  }
};
vector<e> edges[2 * maxn];
bool vis[maxn];
int dis[maxn];
void dijkstra(){
  memset(vis,0,sizeof(vis));
  for(ll i = 0;i <= n;i++){
    dis[i] = 2147483647;
  }
  priority_queue<e> q;
  q.push({0,0});
  while(!q.empty()){

  }
}
void addedge(ll u,ll v,ll w){

}
int main(){
  return 0;
}
