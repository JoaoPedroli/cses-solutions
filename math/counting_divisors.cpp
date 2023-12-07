#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n; cin>>n;
  int ans, x;
  for(int i = 0; i < n; ++i) {
    cin>>x;
    ans = 1 + (x != 1);
    for(int j = 2; j * j <= x; ++j) {
      if(x % j == 0) {
        if(j != x / j) ans += 2;
        else ++ans;
      }
    }
    cout<<ans<<'\n';
  }
}
