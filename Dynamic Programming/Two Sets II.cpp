///Two Sets II - Yassine Hajji
#include<bits/stdc++.h>

using namespace std;

const int N = 5001, SUM = (500*501)/2+1, MOD = 1e9+7;

int n;
long long dp1[SUM], dp2[SUM];

long long poww(long long x, long long y){
    if(y == 0) return 1;
    long long ans = poww(x, y/2);
    ans = (ans * ans) % MOD;
    if(y%2) ans = (ans * x) % MOD;
    return ans;
}

int main() {
    cin>>n;
    int m = n*(n+1)/2;
    if(m%2){
        cout<<0;
        return 0;
    }
    dp1[0] = 1;
    for(int pos=1; pos<=n; pos++){
        for(int sum=1; sum<=m; sum++){
            dp2[sum] = dp1[sum];
            if(sum >= pos)
                dp2[sum] = (dp2[sum] + dp1[sum-pos]) % MOD;
        }
        for(int sum=1; sum<=m; sum++)
            dp1[sum] = dp2[sum];
    }
    cout<<(dp1[m/2]*poww(2, MOD-2)) % MOD;
    return 0;
}
