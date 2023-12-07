#include <bits/stdc++.h>
#define int long long
using namespace std;

int fpow(int b, int e, int m) {
  int result = 1;

  while (e > 0) {
    if (e & 1LL)
      result = (result * b) % m;

    e = e >> 1LL;

    b = (b * b) % m;
  }

  return result;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n; cin>>n;
  for(int i = 0; i < n; ++i) {
    int a, b; cin>>a>>b;
    cout<<fpow(a, b, 1e9+7)<<'\n';
  }
}
