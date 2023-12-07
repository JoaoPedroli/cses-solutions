#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 2e5+5;
int n, ns[MAX];

int f(int x) {
  int soma = 0;
  for(int i = 0; i < n; ++i) {
    soma += abs(ns[i] - x);
  }
  return soma;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  cin>>n;
  int ma = 0;
  for(int i = 0; i < n; ++i) {
    cin>>ns[i];
    ma = max(ma, ns[i]);
  }
  int lo = 0, hi = 1e9+5;
  for(int i = 0; lo != hi && i < 50; ++i) {
    const int delta = floor((hi - lo) / 3.0);
    
    int m1 = lo + delta;
    int m2 = hi - delta;
    const int aux_m1 = f(m1);
    const int aux_m2 = f(m2);
    if(aux_m1 < aux_m2) {
      hi = m2;
    } else if(aux_m1 >= aux_m2) {
      lo = m1;
    }
  }

  int me = f(hi);
  int cur = me;
  while(1) {
    --hi;
    if(hi < 0) break;
    cur = f(hi);
    if(cur < me) me = cur;
    else break;
  }
  ++hi;

  cout<<f(hi)<<'\n';
}
