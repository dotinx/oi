#include <stdio.h>
#include <stdlib.h>
void _(){
	unsigned long long a,b,c,d;
	scanf("%I64u%I64u%I64u",&a,&b,&c);
	for(d=0;b;a=(a+a)%c,b>>=1)
	 if(b&1)d=(d+a)%c;
	printf("%I64u\n",d);
}

int main() {
	freopen("program1.out","w",stdout);
	_();
	_();
	_();
	_();
	_();

	_();
	_();
	_();
	_();
	_();
}
