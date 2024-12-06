// Skeleton for constests

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// function to check for a valid array straight from part 1
bool valid(vector<ll> &B){
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

// function to check for validity of the array by removing the element at a particular index i
bool remove(int i, vector<ll> &A){
   vector<ll> B = A;
   B.erase(B.begin()+i);
   return valid(B);
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
      int flag=0;
      if(valid(A[i])) flag=1;
      for(int j=1; j<A[i].size(); j++){
         if(flag==1) break;
         int diff1 = A[i][j] - A[i][j-1];
         // check for unacceptable difference, that is outside the range of [1,3]
         if(abs(diff1)<1 || abs(diff1)>3){
            if(remove(j,A[i]) || remove(j-1,A[i])) flag=1;
         }
         // check for break in strict monotonicity
         if(j<A[i].size()-1){
            int diff2 = A[i][j+1] - A[i][j];
            if((diff1>0) != (diff2>0)){
               if(remove(j,A[i]) || remove(j-1,A[i]) || remove(j+1,A[i])) flag=1;
            }
         }
      }
      // if any removal gives a valid sequence, then count it
      if(flag==1) ans++;
   }

   cout<<ans;
   

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}


