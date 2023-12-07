#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int j) {
  return j * (2 + (j * 2)) / 2 + 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int t; cin>>t; while(t--) {
    int x, y; cin>>x>>y;
    --x, --y;
    if(x <= y) {
      const int ref = f(y);
      const int diff = y - x;
      if(y&1) {
        cout<<ref - diff<<'\n';
      } else {
        cout<<ref + diff<<'\n';
      }
    } else {
      const int yy = y + (x - y), ref = f(yy);
      const int diff = yy - y;
      if(yy&1) {
        cout<<ref + diff<<'\n';
      } else {
        cout<<ref - diff<<'\n';
      }
    }
  }
}
