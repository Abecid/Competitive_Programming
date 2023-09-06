#include<bits/stdc++.h>
using namespace std;
int n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n>=4&&(n%2==0)){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}