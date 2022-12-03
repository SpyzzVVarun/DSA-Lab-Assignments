#include "functions.h"

int main()
{
    Graph g(4);
    g.AddEdges(0,1,4);
    g.AddEdges(0,2,3);
    g.AddEdges(2,3,2);
    g.AddEdges(1,3,-11);
    g.FloydWarshall();
    cout << endl;
    g.Djikastra(0);
    cout << endl;
    g.BellmanFord(0);
    return 0;
}