// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        Node *even = NULL, *odd = NULL, *evenStart = NULL, *oddStart = NULL;
        Node *ptr = head;
        while (ptr)
        {
            if (ptr->data % 2 == 0)
            {
                if (even == NULL)
                {
                    even = ptr;
                    evenStart = ptr;
                }
                else
                {
                    even->next = ptr;
                    even = ptr;
                }
            }
            else
            {
                if (odd == NULL)
                {
                    odd = ptr;
                    oddStart = ptr;
                }
                else
                {
                    odd->next = ptr;
                    odd = ptr;
                }
            }
            ptr = ptr->next;
        }
        if (not evenStart)
        {
            odd->next = NULL;
            return oddStart;
        }
        if (not oddStart)
        {
            even->next = NULL;
            return evenStart;
        }
        even->next = oddStart;
        odd->next = NULL;
        return evenStart;
    }
};

// { Driver Code Starts.

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends