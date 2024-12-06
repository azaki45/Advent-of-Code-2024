// Skeleton for constests

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int flag=0;
   ll a;
   vector<ll> list1,list2;
   while(cin >> a){
      if(flag==0){
         list1.push_back(a);
         flag=1;
      }
      else{
         list2.push_back(a);
         flag=0;
      }
   }

   sort(list1.begin(), list1.end());
   sort(list2.begin(), list2.end());

   ll ans=0;
   for(int i=0; i<list1.size(); i++){
      ans+=abs(list1[i]-list2[i]);
   }
   cout<<ans;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}


