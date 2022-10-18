#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n,q,a[MAXN],lmin[MAXN];
int t,l,r;
int main(){
  scanf("%d%d",&n,&q);
  for(int i = 1;i <= n;i++){
    scanf("%d",&t);
    lmin[i] = max(lmin[i - 1],a[t] + 1);
    a[t] = i;
  }
  for(int i = 1;i <= q;i++){
    scanf("%d%d",&l,&r);
    if(lmin[r] <= l)
      printf("Yes\n");
    else
      printf("No\n");
  }
}
