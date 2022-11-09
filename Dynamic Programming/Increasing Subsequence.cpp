///Increasing Subsequence - Yassine Hajji
#include<bits/stdc++.h>

using namespace std;

const int N = 200001;

template<class T> struct Seg {
	const T ID = 0;
	T comb(T a, T b) { return max(a, b); }
	int len; vector<T> seg;
	void init(int _len) { len = _len+1; seg.assign(2*len, ID); }
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
};
Seg<int> st;

int n, tab[N];

int main() {
    cin>>n;
    set<int> s;
    map<int, int> mp;
    for(int i=1; i<=n; i++){
        cin>>tab[i];
        s.insert(tab[i]);
    }
    ///Array Values Compression
    int cnt = 0;
    for(int i : s) mp[i] = ++cnt;
    for(int i=1; i<=n; i++)
        tab[i] = mp[tab[i]];
    ///Searching Best Answer
    st.init(cnt);
    int ans = 0;
    for(int i=1; i<=n; i++){
        int val = st.query(0, tab[i]-1) + 1;
        if(val > st.query(tab[i], tab[i]))
            st.upd(tab[i], val);
        ans = max(ans, val);
    }
    cout<<ans;
    return 0;
}
