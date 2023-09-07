#include <bits/stdc++.h>
using namespace std;
 
int64_t n, x, v, ans = 0, soma = 0;
map<int64_t, int64_t> mp;
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  cin>>n;
  mp[0] = 1;
  for(int i = 0; i < n; ++i) {
    cin>>v;
    soma = ((soma % n) + (v % n) + n) % n;
    ans += mp[soma];
    mp[soma]++;
  }
 
  cout<<ans<<'\n';
}
