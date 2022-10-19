#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
ull qpow(ull a, ull b, ull p){
    ull res = 1 % p;
    while (b){
        if (b&1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int main(){
  ull a,b,p;
  cin >> a >> b >> p;
  cout << a << "^" << b << " mod " << p << "=" << qpow(a,b,p) << endl;
  return 0;
}
