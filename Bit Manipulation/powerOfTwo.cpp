// { Driver Code Starts
//Initial Template for C++

#include  <bits/stdc++.h>
using namespace std;

/User function Template for C++

class Solution
{

ic:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {

      return (__builtin_popcountll(n) != 1 ? false : true);
    }
};

// { Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin  > >  t; //testcases

    for  (int  i  =   0 ;  i < t; i++)
    {
        long long n; //input a number n
        cin  > > n;

        Solution ob;
       if  (ob.isPowerofTwo(n))  //Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
            out  <<  "YES "  << endl;
        lse
            cout  < < "N O"  << e    }

    return 0;
}
// } Driver Code Ends