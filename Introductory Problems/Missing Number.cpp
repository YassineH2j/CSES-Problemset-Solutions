//Missing Number - Yassine Hajji
#include<bits/stdc++.h>

using namespace std;

bool vis[200001];

int main() {
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
            int x;
            cin>>x;
            vis[x] = true;
    }
    for(int i=1; i<=n; i++){
        if(vis[i] == false){
            cout<<i<<endl;
            return 0;
        }
    }
}
