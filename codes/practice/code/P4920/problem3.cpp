#include <stdio.h>
unsigned long long s0,s1,s2,s3,s4,i,j,n;
typedef unsigned long long ULL;
ULL gcd(ULL u,ULL v){return v?gcd(v,u%v):u;}
int main() {
  freopen("program3.out","w",stdout);
	scanf("%I64u", &n);
	s0=n+1;
	i=2;
	s1=n/gcd(n,i);i=i/gcd(n,i);
	s1=(n+1)/gcd(n+1,i)*s1;
	i=6;
	s2=n/gcd(n,i);i/=gcd(n,i);
	s2=(n+1)/gcd(n+1,i)*s2;i/=gcd(n+1,i);
	s2=(2*n+1)/gcd(2*n+1,i)*s2;
	s3=s1*s1;
	i=30;
	s4=n/gcd(n,i);i/=gcd(n,i);
	s4=(n+1)/gcd(n+1,i)*s4;i/=gcd(n+1,i);
	s4=(2*n+1)/gcd(2*n+1,i)*s4;i/=gcd(2*n+1,i);
	if(i==5){
		j=(n-1)/gcd(n-1,i);i/=gcd(n-1,i);
		j=(n+2)/gcd(n+2,i)*j;
		j=j*3+1;
	}else j=3*n*(n+1)-1;
	s4=s4*j;
	printf("%I64u\n%I64u\n",s0,s0);
	printf("%I64u\n%I64u\n",s1,s1);
	printf("%I64u\n%I64u\n",s2,s2);
	printf("%I64u\n%I64u\n",s3,s3);
	printf("%I64u\n%I64u\n",s4,s4);
	return 0;
}
