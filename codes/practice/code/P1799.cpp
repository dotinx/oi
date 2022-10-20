#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int f[MAXN][MAXN];
int n,a[MAXN],ans = 0;
int main(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i++){
    scanf("%d",&a[i]);
  }
  memset(f,0,sizeof(f));
  for(int i = 1;i <= n;i++){
    for(int j = 0;j <= i;j++){
      if (j>0) f[i][j]=f[i-1][j-1];
			f[i][j]=max(f[i-1][j]+(a[i]==i-j),f[i][j]);
			ans=max(ans,f[i][j]);
    }
  }
  printf("%d\n",ans);
  return 0;
}
