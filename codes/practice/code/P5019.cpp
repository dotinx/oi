#include<bits/stdc++.h>
using namespace std;
int road[100010],ans = 0;
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 1;i <= n;i++)
    scanf("%d",road + i);
  for(int i = 2;i <= n;i++)
    if(road[i] > road[i - 1])
      ans+=road[i]-road[i-1];
  printf("%d\n",ans + road[1]);
  return 0;
}
