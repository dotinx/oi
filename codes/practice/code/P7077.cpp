#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 100010,mod = 998244353;

int n,m;

int cnt[maxn];//cnt -> 函数的执行次数
int data[maxn],type[maxn];//data -> 数据串，type ->操作
int mule[maxn];//对操作2的因数
int add[maxn],pos[maxn];//对操作1的加数与位置

int main(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i++) scanf("%d",data + i);
  scanf("%d",&m);
}
