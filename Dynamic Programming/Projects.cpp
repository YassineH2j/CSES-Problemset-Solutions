///Projects - Yassine Hajji
#include<bits/stdc++.h>

using namespace std;

const int N = 400001;

int n;
long long dp[N];
vector<pair<int, int>> st[N];

int main() {
    cin>>n;
    map<int, int> mp;
    vector<array<int, 3>> vec;
    for(int i=1; i<=n; i++){
            int a, b, p;
            cin>>a>>b>>p;
            mp[a];
            mp[b];
            vec.push_back({a, b, p});
    }
    ///Array Values Compression
    int cnt = 0;
    for(auto &i : mp){
        i.second = ++cnt;
    }
    for(int i=0; i<n; i++){
        int a = vec[i][0], b = vec[i][1], p = vec[i][2];
        st[mp[b]].push_back({mp[a], p});
    }
    ///Searching Best Answer
    for(int i=1; i<=cnt; i++){
        dp[i] = dp[i-1];
        for(auto[a, p] : st[i])
            dp[i] = max(dp[i], dp[a-1]+p);
    }
    cout<<dp[cnt];
    return 0;
}
