#include <bits/stdc++.h>
using namespace std;

int fpow(int b, int e, int m) {
  int result = 1;
  b %= m;
  while (e > 0) {
    if (e&1) result = (1ll * result * b) % m;
    e >>= 1;
    b = (1ll * b * b) % m;
  }
  return result;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n; cin>>n;
  for(int i = 0; i < n; ++i) {
    int a, b; cin>>a>>b;
    cout<<fpow(a, b, 1e9+7)<<'\n';
  }
}
