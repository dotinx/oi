#include<bits/stdc++.h>
using namespace std;
int t,m,n,ans;
int dfs(int pos,int now,int left){
  if(pos == n && left == 0) return ans = ans + 1;
  if(pos == n) return 0;
  for(int i = now;i <= left;i++)
    dfs(pos + 1,i,left - i);
  return 0;
}
int main(){
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&m,&n);
    ans = 0;
    dfs(0,0,m);
    printf("%d\n",ans);
  }
}
