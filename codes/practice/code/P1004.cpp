#include<bits/stdc++.h>
using namespace std;
long long val[180][90][90],w[90][90],n;
int main(){
  scanf("%lld",&n);
  memset(w,0,sizeof(w));
  while (true){
    long long x,y,m;
    scanf("%lld%lld%lld",&x,&y,&m);
    if(x == 0 && y == 0 && m == 0) break;
    w[y][x] = m;
  }
  memset(val,-1,sizeof(val));
  val[2][1][1] = w[1][1];
  for(long long k = 3;k < n + n;k++)
    for(long long i1 = 1;i1 < n;i1++)
      for(long long i2 = i1 + 1;i2 <= n;i2++){
        long long s = val[k][i1][i2];
        s = max(val[k - 1][i1][i2],s);
        s = max(val[k - 1][i1 - 1][i2],s);
        s = max(val[k - 1][i1][i2 - 1],s);
        s = max(val[k - 1][i1 - 1][i2 - 1],s);
        if(s == -1) continue;
        val[k][i1][i2] = s + w[k-i1][i1] + w[k - i2][i2];
      }
  printf("%lld\n",val[n + n - 1][n - 1][n] + w[n][n]);
  return 0;
}
