#include <iostream>
#include <map>
#include <list>
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
        for (auto p : adjlist)
        {
            cout << p.first << " : ";
            for (auto a : p.second)
            {
                cout << a.first << '(' << a.second << ") ,";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph<char> g;
    g.addEdge('0', '1', 4, 0);
    g.addEdge('0', '7', 8, 0);
    g.addEdge('1', '7', 11, 0);
    g.addEdge('1', '2', 8, 0);
    g.addEdge('7', '8', 7, 0);
    g.addEdge('2', '8', 2, 0);
    g.addEdge('8', '6', 6, 0);
    g.addEdge('2', '5', 4, 0);
    g.addEdge('6', '5', 2, 0);
    g.addEdge('2', '3', 7, 0);
    g.addEdge('3', '3', 14, 0);
    g.addEdge('3', '4', 9, 0);
    g.addEdge('5', '4', 10, 0);
    g.addEdge('7', '6', 1, 0);
    g.printGraph();
    return 0;
}