//Palindrome Reorder - Aziz Smiri
#include<bits/stdc++.h>

using namespace std;

int occ[26] ;
int main() {
    string s ;
    cin>>s ;
    for(char c : s){
        occ[c-'A']++ ;
    }
    string s1 = "" , s2 = "" ;
    int nbodd = 0 ;
    for(int i = 0 ; i<26 ; i++){
        nbodd += occ[i]%2 ;
        if(occ[i]%2==0){
            for(int j = 1 ; j<=occ[i]/2 ; j++){
                s1 += char('A' + i) ;
            }
        }
        else{
            for(int j = 1 ; j<=occ[i] ; j++){
                s2 += char('A' + i) ;
            }
        }
    }
    if(nbodd>1){
        cout<<"NO SOLUTION"<<endl;
        return 0 ;
    }
    string s3 = s1 ;
    reverse(s3.begin() , s3.end()) ;
    cout<<s1 + s2 + s3 <<endl;
    return 0;
}
