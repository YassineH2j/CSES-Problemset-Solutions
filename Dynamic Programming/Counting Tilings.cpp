///Counting Tilings - Yassine Hajji
#include<bits/stdc++.h>

using namespace std;

const int N = 1024, MOD = 1e9+7;

int n;
vector<int> adj[N];

int main() {
    int n, m;
    cin>>n>>m;
    int p = 1;
    for(int i=1; i<=n; i++) p *= 2;
    for(int i=0; i<p; i++){
        for(int j=0; j<p; j++){
                bool b = true;
                int k=0;
                while(k < n){
                    if(((i>>k)&1) == 1 && ((j>>k)&1) == 1){
                        b = false;
                        break;
                    }
                    int l = k;
                    while(l<n && ((i>>l)&1) == 0 && ((j>>l)&1) == 0)
                        l++;
                    if((l-k) % 2){
                        b = false;
                        break;
                    }
                    k = max(k+1, l);
                }
                if(b) adj[j].push_back(i);
        }
    }
    vector<int> a(p, 0);
    a[0] = 1;
    while(m--){
        vector<int> b(p, 0);
        for(int i=0; i<p; i++){
            for(int j : adj[i]) b[i] = (b[i] + a[j]) % MOD;
        }
        for(int i=0; i<p; i++){
            a[i] = b[i];
        }
    }
    cout<<a[0];
    return 0;
}
