#include<bits/stdc++.h>
using namespace std;
typedef __int128 int128;
int128 n,m,a[85][85],f[85][85];
void read(int128 &s){
	s=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while('0'<=c&&c<='9'){
		s=s*10;
		s=s+c-48;
		c=getchar();
	}
}
void print(int128 s){
  if(s > 9) print(s / 10);
  putchar(x%10+'0');
}
int128 dfs(int l,int r,int x,int s)
{
	if(f[l][r])
    return f[l][r];
	if(l>r)
    return 0;
	f[l][r] = max(dfs(l+1,r,x,s+1)+a[x][l]*(qpow(2,s))
               ,dfs(l,r-1,x,s+1)+a[x][r]*(qpow(2,s)));
	return f[l][r];
}
int128 qpow(int128 a,int128 b){
	int128 s=1;
	while(b){
		if(b%2) s*=a;
		a=a*a;
		b>>=1;
	}
	return s;
}
int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        read(a[i][j]);
  	for(int i=1;i<=n;i++){
      memset(f,0,sizeof(f));
      ans = ans + dp(1,m,i,1);
    }//ans为所有行之和
  	print(ans);
    // scanf("%d%d",&n,&m);
    // for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= m;j++){
    //         int t;
    //         scanf("%d",&t);
    //         w[i].push_back(t);
    //     }
    // }
    // /*for(int i = 0;i < m;i++){
    //     for(int j = 0;j < n;j++){
    //         int t = w[i].front();w[i].pop_front();
    //         printf("%d",t);
    //     }
    // }*/
    // for(int i = 1;i <= m;i++){
    //     for(int j = 1;j <= n;j++){
    //         int f = w[j].front(),e = w[j].back();
    //         if(f > e){
    //             ans = ans +  e * pow(2,i);
    //             w[j].pop_back();
    //         }else{
    //             ans = ans +  f * pow(2,i);
    //             w[j].pop_front();
    //         }
    //
    //     }
    // }
    // printf("%llu\n",ans);
    return 0;
}
