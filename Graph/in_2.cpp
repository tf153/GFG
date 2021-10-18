#include <iostream>
using namespace std;
// template <typename T>
class stack
{
    char arr[999];
    int curr, start;
    int size;

public:
    stack()
    {
        curr = 0;
        size = 0;
        // start=0;
    }
    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
    void push(char c)
    {
        arr[curr] = c;
        curr++;
        size++;
    }
    char top()
    {
        if (!empty())
            return arr[curr - 1];
        return '0';
    }
    void pop()
    {
        curr--;
        size--;
    }
};
int main()
{
    string str;
    stack st;
    char ch;
    cin >> str;
    for (char c : str)
    {
        st.push(c);
    }
    while (!st.empty())
    {
        ch = st.top();
        cout << ch;
        st.pop();
    }
    return 0;
}