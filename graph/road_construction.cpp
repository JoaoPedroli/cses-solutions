#include <bits/stdc++.h>
using namespace std;
 
struct DSU {
	vector<int> p, rnk, tam;
	int comps, ma = 0;
 
	DSU(int n) {
		p.assign(n+1, 0);
		iota(p.begin(), p.end(), 0);
		rnk.assign(n+1, 0);
		tam.assign(n+1, 1);
		comps = n;
	}
 
	int id(int u) {
		return (p[u] == u ? u : p[u] = id(p[u]));
	}
 
	bool same(int u, int v) {
		return id(u) == id(v);
	}
	
	void join(int u, int v) {
		if(same(u, v)) return;
		int U = id(u), V = id(v);
		if(rnk[U] < rnk[V]) swap(U, V);
		p[U] = V;
		if(rnk[U] == rnk[V]) ++rnk[V];
		tam[V] += tam[U];
    ma = max(ma, tam[V]);
		--comps;
	}
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 
  int n, m; cin>>n>>m;
  DSU dsu(n);
  int u, v;
  for(int i = 0; i < m; ++i) {
    cin>>u>>v;
    dsu.join(u, v);
    cout<<dsu.comps<<' '<<dsu.ma<<'\n';
  }
}
