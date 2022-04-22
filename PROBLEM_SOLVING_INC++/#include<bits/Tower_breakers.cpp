#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d",&n);
        scanf("%d",&m);
        if(n%2==1 && m!=1)
            cout<<1<<"\n";
        else
            cout<<2<<"\n";
    }
}
