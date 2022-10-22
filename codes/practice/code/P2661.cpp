#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int f[maxn];
int n;
int getfa(int fa,int &dis){//用&（取地址）传参可以让作用域史诗级加强而且调用无感
  dis += 1;
  if(fa != f[fa]){
    return getfa(f[fa],dis);
  }else{
    return fa;
  }
}
int depth,tmp,ans = 2147483647;
int main(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i++) f[i] = i;
  for(int i = 1;i <= n;i++){
    scanf("%d",&tmp);
    depth = 0;
    if(getfa(tmp,depth) == i){
      ans = min(ans,depth);
    }else{
      f[i] = tmp;
    }
  }
  printf("%d\n",ans);
}
