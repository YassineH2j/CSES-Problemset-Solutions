///Removal Game - Yassine Hajji
#include<bits/stdc++.h>

using namespace std;

const int N = 5001;

int n, tab[N];
long long dp[N][N];

int main() {
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>tab[i];
    }
    for(int len = 1; len<=n; len++){
        for(int pos=1; pos<=n-len+1; pos++){
            if(len%2 == n%2)
                dp[pos][len] = max(tab[pos+len-1] + dp[pos][len-1], tab[pos] + dp[pos+1][len-1]);
            else
                dp[pos][len] = min(dp[pos][len-1], dp[pos+1][len-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}
