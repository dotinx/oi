#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t,n,unsolved;
bool isGood(string str){
  unsolved = 0;
  for(ll i = 0,strl = str.length();i < strl;i++){
    if(str[i] == 'Q') unsolved += 1;
    if(str[i] == 'A') unsolved = unsolved == 0 ? 0 : unsolved - 1;
  }
  return !unsolved;
}
int main(){
  scanf("%d",&t);
  while(t--){
    string strr;
    scanf("%d",&n);
    cin >> strr;
    if(isGood(strr))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
