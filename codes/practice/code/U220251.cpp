#include <bits/stdc++.h>
using namespace std;
long long a,n,k;
queue<long long> q;
priority_queue<long long,vector<long long>,greater<long long> > p;
bool vis[5 * 500000],flag = false;
vector<long long> s,task;
long long cnt = 0,maxm = 0;
signed main(){
  scanf("%lld%lld%lld",&a,&k,&n);
  task.resize(n + 5);
  for(long long i = 0 ; i < n;i++){
    scanf("%lld",&task[i]);
    maxm = max(maxm,task[i]);
  }
  q.push(a);
  while(!q.empty()){
    long long that = q.front();q.pop();
    if(that > maxm * 100){
        vis[that] = true;
        continue;
    }
    if(!vis[that]) p.push(that);
    vis[that] = true;
    if((!vis[2 * that + 1]) and (2 * that + 1 < maxm + 10)) q.push(2 * that + 1);
    if((!vis[3 * that + 1]) and (3 * that + 1 < maxm + 10)) q.push(3 * that + 1);
    if((!vis[5 * that - 1]) and (5 * that - 1 < maxm + 10)) q.push(5 * that - 1);
  }
  while(!p.empty()){
    long long that = p.top();p.pop();
    if(that > maxm + 10) break;
    if(cnt % k == 0 and !flag){
      flag = true;
      continue;
    }
    if(flag) flag = true;
    cnt++;
    s.push_back(that);
  }
  for(long long i = 0; i < n;i++){
    printf("%lld\n",s[i]);
  }
  // for(long long i = 0;i < cnt;i++){
  //   printf longf("%d\n",s[i]);
  // }
  return 0;
}
