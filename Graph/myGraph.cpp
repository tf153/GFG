#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stack>
using namespace std;
template <typename T>
class Graph
{
private:
    map<T, list<pair<T, int>>> adjlist;

public:
    void addEdge(T u, T v, int weight, bool bidirectional = false)
    {
        adjlist[u].push_back({v, weight});
        if (bidirectional)
            adjlist[v].push_back({u, weight});
    }
    void printGraph()
    {
        for (pair<T, list<pair<T, int>>> p : adjlist)
        {
            cout << p.first << " : ";
            for (pair<T, int> a : p.second)
            {
                cout << a.first << '(' << a.second << ") ";
            }
            cout << endl;
        }
    }
    void bfs(T u)
    {
        map<T, bool> visited;
        queue<T> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty())
        {
            int len = q.size();
            cout << " ( ";
            for (int i = 0; i < len; i++)
            {
                cout << ' ' << q.front() << ' ';
                for (pair<T, int> p : adjlist[q.front()])
                {
                    if (!visited[p.first])
                    {
                        visited[p.first] = true;
                        q.push(p.first);
                    }
                }
                q.pop();
            }
            cout << " ) -> ";
        }
        return;
    }
    void dfs(T u)
    {
        map<T, bool> visited;
        stack<T> st;
        st.push(u);
        visited[u] = true;
        while (!st.empty())
        {
            cout << st.top() << " -> ";
            T removed = st.top();
            st.pop();
            for (pair<T, int> p : adjlist[removed])
            {
                if (!visited[p.first])
                {
                    visited[p.first] = true;
                    st.push(p.first);
                }
            }
        }
        return;
    }
};
int main()
{
    {
        //bfs
        //dfs
        Graph<char> g;
        g.addEdge('0', '1', 4, 0);
        g.addEdge('0', '7', 8, 0);
        g.addEdge('1', '7', 11, 0);
        g.addEdge('1', '2', 8, 0);
        g.addEdge('7', '8', 7, 0);
        g.addEdge('2', '8', 2, 0);
        g.addEdge('8', '6', 6, 0);
        g.addEdge('2', '5', 4);
        g.addEdge('6', '5', 2);
        g.addEdge('2', '3', 7);
        g.addEdge('3', '3', 14);
        g.addEdge('3', '4', 9);
        g.addEdge('5', '4', 10);
        g.addEdge('7', '6', 1);
        //g.printGraph();
        g.bfs('0');
        cout << endl;
        g.dfs('0');
    }
    return 0;
}