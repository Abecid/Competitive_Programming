
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int t,n,a[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int mn=1e9+1,mx=0,posn=-1,posx=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>=mx){
				mx=a[i];
				posx=i;
			}
			if(a[i]<=mn){
				mn=a[i];
				posn=i;
			}
		}
		printf("%d %d\n",posn,posx);
	}
	return 0;
}