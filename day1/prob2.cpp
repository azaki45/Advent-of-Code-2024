// Skeleton for constests

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
   int flag=0;
   ll a;
   map<ll,ll> mp;
   vector<ll> list1,list2;
   while(cin >> a){
      if(flag==0){
         list1.push_back(a);
         flag=1;
      }
      else{
         list2.push_back(a);
         mp[a]++;
         flag=0;
      }
   }

   // cout<<list1[0]<<" "<<list1[list1.size()-1]<<endl;
   // cout<<list2[0]<<" "<<list2[list1.size()-1]<<endl;

   // sort(list1.begin(), list1.end());
   // sort(list2.begin(), list2.end());

   ll ans=0;
   for(int i=0; i<list1.size(); i++){
      ans+=list1[i]*mp[list1[i]];
   }
   cout<<ans;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}


