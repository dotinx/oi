#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  scanf("%d",&n);
  if(n % 4 == 1){
    for(int i = 1;i <= n / 4;i++){
      printf("0011");
    }
    printf("0\n");
  }else{
    printf("-1\n");
  }
  return 0;
}
