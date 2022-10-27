#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,w[12980],f[12980],v[12980];
  scanf("%d%d",&n,&m);
  for(int i = 1;i <= n;i++){
    scanf("%d",&w[i]);
    scanf("%d",&v[i]);

  }
  for(int i = 1;i <= n;i++){
    for(int l = m;l >= w[i];l--){
      f[l] = max(f[l],f[l - w[i]] + v[i]);
    }
  }
  printf("%d\n",f[m]);
  return 0;
}
