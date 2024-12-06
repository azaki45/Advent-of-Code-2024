// Skeleton for constests

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool valid(vector<ll> B){
   int flag1=0, flag2=0;

   for(int j=1; j<B.size(); j++){
      if(j==1 && B[j]>B[j-1]) flag1=1;
      ll diff = abs(B[j]-B[j-1]);
      if(!(diff>=1 && diff<=3)) flag2=1;
      if(flag1==1 && B[j]<B[j-1]) flag2=1;
      else if(flag1==0 && B[j]>B[j-1]) flag2=1;
   }
   if(flag2==0) return true;
   return false;
}

void solve()
{
   ll a;

   vector<vector<ll>> A;
   string s;
   while(getline(cin, s)){
      s+=' ';
      vector<ll> B;
      string num="";
      for(int i=0; i<s.length(); i++){
         if(s[i]!=' ') num+=s[i];
         else{
            B.push_back(stoi(num)*1LL);
            num="";
         }
      }
      A.push_back(B);
   }
   int n = A.size();


   ll ans = 0;
   
   for(int i=0; i<n; i++){

      // for(int j=1; j<A[i].size(); j++){
         
      // }
      if(valid(A[i])) ans++;
   }

   cout<<ans;
   

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}


