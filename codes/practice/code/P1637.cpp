#include<bits/stdc++.h>
using namespace std;
const int MAXN = 30000 + 50;
typedef long long int ll;


int n;
int s[MAXN],t1[MAXN],t2[MAXN],pre[MAXN];
ll ans=0;
/*树状数组板子 特定k(加数)=1*/
inline ll lowbit(ll x){
    return x&(-x);
}
void update(ll i){
    while(i <= n){
        s[i] += 1;
        i += lowbit(i);
    }
}
ll getsum(ll i){
    ll res = 0;
    while(i > 0){
        res += s[i];
        i -= lowbit(i);
    }
    return res;
}

struct node{
  int pos,num;
  friend bool operator<(const node &a,const node &b){
    return a.num < b.num;
  }
} nodes[MAXN];

int main() {
  scanf("%d",&n);
  for(int i = 1;i <= n;i++){
    scanf("%d",&nodes[i].num);
    nodes[i].pos = i;
  }
  sort(nodes + 1,nodes + n + 1);
  for(int i=1;i<=n;++i) {
    if(nodes[i].num!=nodes[i-1].num||i==1)
      pre[nodes[i].pos]=i;
    else
      pre[nodes[i].pos]=pre[nodes[i-1].pos];
  }
  for(int i=1;i<=n;++i){
      t1[i]=getsum(pre[i]-1);
      update(pre[i]);
  }
  memset(s,0,sizeof(s));
  for(int i=n;i>=1;--i){
      t2[i]=getsum(n-pre[i]);
      update(n-pre[i]+1);
  }
  for(int i=1;i<=n;++i)
    ans+=t1[i]*t2[i];
  printf("%lld \n",ans);
  return 0;
}
