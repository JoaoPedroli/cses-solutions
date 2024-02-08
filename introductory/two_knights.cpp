#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  map<int, int> mp;
  mp[1] = 0, mp[2] = 6, mp[3] = 28, mp[4] = 96, mp[5] = 252, mp[6] = 550, mp[7] = 1056;
  int t; cin>>t;
  for(int k = 1; k <= t; ++k) {
    if(k < 8) {
      cout<<mp[k]<<'\n';
      continue;
    }
    const long long tot = k * k;
    const long long c8 = ((k - 4) * (k - 4)) * (tot - 9);
    const long long c6 = ((k - 4) * 4) * (tot - 7);
    const long long c4 = (4 + (k - 4) * 4) * (tot - 5);
    const long long c3 = 8 * (tot - 4);
    const long long c2 = 4 * (tot - 3);
    cout<<(c8 + c6 + c4 + c3 + c2) / 2<<'\n';
  }
}
