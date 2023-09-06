#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> idx;
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n, x; cin>>n>>x;
  vector<int> ns(n+2);
  for(int i = 1; i <= n; ++i) {
    cin>>ns[i];
    idx[ns[i]].emplace_back(i);
  }
  for(int i = 1; i <= n; ++i) {
    const vector<int> aux = idx[x - ns[i]];
    if(aux.size()) {
      int pos = 0;
      for(int v : aux)
        if(v != i) {
          pos = v;
          break;
        }
      if(pos) {
        cout<<i<<' '<<pos<<'\n';
        return 0;
      }
    }
  }
  cout<<"IMPOSSIBLE\n";
}
