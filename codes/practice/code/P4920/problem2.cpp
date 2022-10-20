#include <stdio.h>
typedef long long LL;
LL n,p;
struct mat{
	LL c[3][3];
	void clear(){
		for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		c[i][j]=0;
	}
}I,Ans;
mat operator *(const mat &a,const mat &b){
	mat pG;
	pG.clear();
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	for(int k=0;k<3;k++)
	pG.c[i][j]=(pG.c[i][j]+a.c[i][k]*b.c[k][j])%p;
	return pG;
}
void _______(){
	scanf("%I64d%I64d",&n,&p);
	Ans.clear();
	Ans.c[0][2]=1;
	I.clear();
	I.c[0][2]=I.c[1][1]=I.c[2][0]=I.c[2][1]=I.c[2][2]=1;
	I.c[1][2]=2;
	for(;n;I=I*I,n>>=1)
	if(n&1)Ans=Ans*I;
	printf("%I64d\n",(Ans.c[0][2]-Ans.c[0][1]*2+Ans.c[0][0]+p+p)%p);
}
int main() {
  freopen("program2.out","w",stdout);
	_______();
	_______();
	_______();
	_______();
	_______();
	_______();
	_______();
	_______();
	_______();
	_______();
	return 0;
}
