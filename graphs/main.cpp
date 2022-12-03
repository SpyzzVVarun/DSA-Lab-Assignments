#include "functions.h"

int main() 
{
    int num = 4;
    Graph g(num);
    g.add_edges(0, 1);
    g.add_edges(0, 2);
    g.add_edges(1, 3);
    cout << "BFS: " << endl; 
    g.BFS(1);
    cout << endl << "DFS: " << endl;
    g.DFS();

  return 0;
}