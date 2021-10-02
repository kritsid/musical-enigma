#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Functiuon to return number of trees

// Return the total number of BSTs possible with keys [1....N] inclusive.
int numTrees(int N) {
    // Your code here
    vector<long long> ans(N+1,0);
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<i;j++)
        {
            ans[i]+=((ans[j]%1000000007)*(ans[i-j-1]%1000000007))%1000000007;
        }
        ans[i]=ans[i]%1000000007;
    }
    return ans[N]%1000000007;
}

// { Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        
        //calling function numTrees()
        cout<<numTrees(n)<<"\n";
    }
}	  // } Driver Code Ends
