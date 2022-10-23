#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll baoli(ll x,ll k){
  while(k--){
    x += 1;
    x = x % 3 == 0 ? x / 3 : x;
  }
  return x;
}
ll calc(ll x,ll k){
  x = x + k;
  int xm3 = x % 3;
  x = (x - xm3) / 3 + xm3;
  while(x % 3 == 0){
    x /= 3;
  }
  return x;
}
int main(){
  ll x,k,ans;
  scanf("%lld%lld",&x,&k);
  mt19937 irand(time(nullptr));
  if(k <= 4 or irand() <= 10){
    ans = calc(x,k);
  }else{
    ans = baoli(x,k);
  }
  printf("%lld\n",ans);
  return 0;
}
