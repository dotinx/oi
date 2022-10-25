#include <bits/stdc++.h>
using namespace std;
const int maxn = 25100;
int n,a[maxn],f[maxn],t,ans;
bool vis[maxn];
void clean(){//全自动清空数组
  memset(a,0,sizeof(a));
  memset(f,0,sizeof(f));
  memset(vis,0,sizeof(vis));
  n = 0;ans = 0;
}
void dfs(int x,int pos,int last){//x为当前维护的面值，pos为上一个维护的位置，last为上次的i，剪枝
  for(int i = last;i <= n;i++){//从last=1开始，到最终的n逐个取出进行查找。
    if(x + a[i] <= a[n] && !vis[x + a[i]]){//符合要求且没见过
      vis[x + a[i]] = true;//打tag
      f[x + a[i]] = pos;//维护f数组，即“只要把可以用更小的数拼出来的数，就可以删去”
      dfs(x + a[i],pos + 1,i);//下一层
    }
  }
}
int main(){
  scanf("%d",&t);
  while(t--){
    clean();
    scanf("%d",&n);
    ans = n;
    for(int i = 1;i <= n;i++)
      scanf("%d",a + i);
    sort(a + 1,a + n + 1);//先排序，小的在前大的在后，小的有概率可以表示大的
    dfs(0,0,1);//递归求f
    for(int i = 1;i <= n;i++)
      if(f[a[i]] > 0)
        ans -= 1;//如果这个有pos（可以被小的数替代）就在原先的基础上删除
    printf("%d\n",ans);
  }
  return 0;
}
