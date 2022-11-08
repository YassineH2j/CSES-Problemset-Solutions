//Trailing Zeros - Yassine Hajji
#include<bits/stdc++.h>

using namespace std;

int main() {
    long long ans = 0, n, x=5;
    cin >> n;
    while(n>=x){
        ans += n/x;
        x *= 5;
    }
    cout<<ans;
    return 0;
}
