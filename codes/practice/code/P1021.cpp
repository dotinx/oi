#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int a[maxn],b[maxn],w[maxn],N,K,ans = 0;
void dfs(int i);
int dp(int t);
int main(){
  scanf("%d%d",&N,&K);
  a[1] = 1;
  dfs(2);
  for(int i = 1;i <= K;i++)
    printf("%d ",w[i]);
  printf("\nMAX=%d\n",ans);
  return 0;
}
void dfs(int depth){
  int vthis = dp(depth - 1);
  if(depth > K){
    if(vthis - 1 > ans){
      ans = vthis - 1;
      for(int i = 1;i <= K;i++)
        w[i] = a[i];
    }
    return;
  }
  for(int i = vthis;i >= a[depth - 1] + 1;i--){
    a[depth] = i;
    dfs(depth + 1);
  }
  return;
}
int dp(int dend){
  memset(b,0x7f,sizeof(b));
  for(int i = 1;i <= dend;i++)
    b[a[i]] = 1;
  int res=1;
  for(int i = 1;i <= dend;i++)
			if(res > a[i] && b[res - a[i]] + 1 < b[res])
				b[res] = b[res - a[i]] +1;
	while(b[res] <= N){
    res++;
		for(int i = 1;i <= dend;i++)
			if(res > a[i] && b[res - a[i]] + 1 < b[res])
				b[res] = b[res - a[i]] +1;
	}
  return res;
}
