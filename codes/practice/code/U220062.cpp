#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
const ull MOD = 998244353;
ull n,p;
int main(){
  scanf("%llu%llu",&n,&p);
  ull ans = 0;
  for(int i = 1;i <= n;i++){
      ans += (i % p) * (n / i) % MOD;
      // ans %= MOD;
  }
  printf("%llu\n",ans % MOD);
  return 0;
}
