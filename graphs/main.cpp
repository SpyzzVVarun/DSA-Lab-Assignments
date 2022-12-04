#include "functions.h"

int main() 
{
    int num = 6;
    Graph g(num);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.deleteEdge(1, 4);
    g.connectedComponents();
    g.printAdjList();
    cout << "BFS: " << endl; 
    g.BFS(1);
    cout << endl << "DFS: " << endl;
    g.DFS();

  return 0;
}