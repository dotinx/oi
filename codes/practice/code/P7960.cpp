#include<bits/stdc++.h>
using namespace std;
const signed MAXN = 10000000 + 100;
long long t,x[MAXN],f[MAXN],nxt = 1;
bool check(long long x){
  while (x){
    if (x % 10 == 7)
      return 1;
    x = x / 10;
  }
  return 0;
}
void init(){
  memset(x,0,sizeof(x));
  for(long long i = 1; i <= MAXN - 10;i++){
    if(x[i] == 1) continue;
    if(check(i)){
      for (long long j = i; j <= MAXN - 10; j += i)
          x[j] = 1;
      continue;
    }
    f[nxt] = i;
    nxt = i;
  }
}
signed main(){
  init();
  scanf("%lld",&t);
  while(t--){
    long long q;
    scanf("%lld",&q);
    if(x[q]){
      printf("-1\n");
    }else{
      printf("%lld\n",f[q]);
    }
  }
  return 0;
}
