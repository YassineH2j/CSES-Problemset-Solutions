///Yassine Hajji - Oct, 18, 2022

#include <bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forr(i, x, y) for(ll i = x; i <= y; i++)
#define forn(i, x, y) for(ll i = x; i >= y; i--)
using namespace std;

const ll N = 200005;

template<class T> struct Seg {
	const T ID = 0;
	// Seg Tree Function Below (Sum, Min, Max)
	T comb(T a, T b) { return a + b; }
	int len; vector<T> seg;
	void init(int _len) { len = _len; seg.assign(2*len, ID); }
	void pull(int p) { seg[p] = comb(seg[2*p], seg[2*p+1]); }
	void upd(int p, T val) { seg[p += len] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += len, r += len+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra, seg[l++]);
			if (r&1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
	void add(int p, T val) { upd(p, val+query(p, p)); }
};

Seg<ll> st;
int n, q, l[N], r[N], a[N], cnt = 0;
vector<int> adj[N];

void dfs(int node, int parent){
    l[node] = ++cnt;
    for(int i : adj[node])
        if(i != parent) dfs(i, node);
    r[node] = ++cnt;
}

int main(){
    cin>>n>>q;
    forr(i, 1, n)
        cin>>a[i];
    forr(i, 1, n-1){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
    }
    dfs(1, 0);
    st.init(cnt);
    forr(i, 1, n){
        st.upd(l[i], a[i]);
        st.upd(r[i], -a[i]);
    }
    while(q--){
            int type;
            cin>>type;
            if(type==1){
                    int node, val;
                    cin>>node>>val;
                    st.upd(l[node], val);
                    st.upd(r[node], -val);
            }
            else{
                    int node;
                    cin>>node;
                    cout<<st.query(1, l[node])<<endl;
            }
    }
    return 0;
}
