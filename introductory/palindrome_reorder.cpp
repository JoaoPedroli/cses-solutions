#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  string p; cin>>p;
  const int n = p.size();
  map<char, int> mp;
  for(char l : p) mp[l]++;
  char cimp = '*';
  int ok = 1, i = 0, j = n-1;
  for(pair<char, int> v : mp) {
    while(i < j && v.second > 1) p[i] = v.first, p[j] = v.first, v.second -= 2, ++i, --j;
    if(v.second == 1) {
      if(cimp == '*') cimp = v.first;
      else ok = 0;
    }
  }
  if(cimp != '*') p[n/2] = cimp;
  cout<<(ok ? p : "NO SOLUTION")<<'\n';
}
