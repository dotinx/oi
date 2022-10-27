#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll k = 0,x = 0,y = 0;
void exgcd(ll a,ll b){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b);
    k=x;
    x=y;
    y=k-a/b*y;
    return;
}
int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	exgcd(a,b);
	printf("%lld",(x % b + b) % b);
	return 0;
}
