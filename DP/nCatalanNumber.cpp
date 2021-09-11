// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int; // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n)
    {
        cpp_int cat_ = 1;
        for (cpp_int i = 1; i <= n; i++)
        {
            cat_ *= (4 * i - 2);
            cat_ /= (i + 1);
        }
        return cat_;
    }
};

// { Driver Code Starts.

int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    while (t--)
    {

        //taking nth number
        int n;
        cin >> n;
        Solution obj;
        //calling function findCatalan function
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
} // } Driver Code Ends