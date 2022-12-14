#include "global.h"

// Undirected Graph
class Graph 
{
  ll num_ver;
  list<ll>* adj_lists;
  bool* nodes_visited;

    private:

        // Function used to recursively run DFS
        void DFS_visit(ll u)
        {
            nodes_visited[u] = true;
            list<ll> adj_list = adj_lists[u];

            cout << u << " ";

            for (auto i=adj_list.begin();i!=adj_list.end(); ++i)
            {
                ll v = *i;
                if (!nodes_visited[v])
                {   
                    DFS_visit(v);
                }
            }
        }

        // Resetting the nodes_visited attribute
        void reset()
        {
            for (ll vertex=0;vertex<num_ver;++vertex) 
            {
                nodes_visited[vertex] = false;
            } 
        }

    public:
        // Create an undirected graph with given vertices and maintain adjacency list
        Graph(ll vertices) 
        {
            num_ver = vertices;
            adj_lists = new list<ll>[vertices];
        }
        // Add edges to the graph
        void addEdge(ll v, ll u) 
        {
            if(v == u) adj_lists[v].PB(u);
            else
            {
                adj_lists[v].PB(u);
                adj_lists[u].PB(v);
            }
        }

        // Delete graph edges
        void deleteEdge(ll v, ll u)
        {
            if(v == u)
            {
                for(auto it = adj_lists[v].begin(); it != adj_lists[v].end();  it++)
                {
                    if((*it) == u)
                    {
                        adj_lists[v].erase(it);
                        break;
                    }
                }
            }
            else
            {
                for(auto it = adj_lists[v].begin(); it != adj_lists[v].end();  it++)
                {
                    if((*it) == u)
                    {
                        adj_lists[v].erase(it);
                        break;
                    }
                }
                for(auto it = adj_lists[u].begin(); it != adj_lists[u].end();  it++)
                {
                    if((*it) == v)
                    {
                        adj_lists[u].erase(it);
                        break;
                    }
                }
            }
        }

        // Function to print adjacency list
        void printAdjList()
        {
            for(int i = 0; i < num_ver; i++)
            {
                cout << "\nAdjacency list of vertex " << i << "\n " << i;
                for (auto j = adj_lists[i].begin(); j != adj_lists[i].end(); j++)
                {
                    cout << " -> " << *j;
                }
            }
            cout << "\n\n";
        }

        // BFS algorithm
        void BFS(ll source) 
        {
            // Initializing all nodes as unvisited nodes
            nodes_visited = new bool[num_ver];
            for (ll i = 0; i < num_ver; i++)
                nodes_visited[i] = false;

            // Queue to implemnt BFS
            list<ll> queue;

            // Marking source node as visited and enqueuing
            nodes_visited[source] = true;
            queue.PB(source);

            // Queue will not be empty till all nodes reachable from source node have not been visited
            while (!queue.empty()) 
            {
                ll u = queue.front();
                cout << u << " ";
                queue.pop_front();
                // Visiting adjacency list of the dequeued node and enqueuing
                for (auto i = adj_lists[u].begin(); i != adj_lists[u].end(); ++i) 
                {
                    ll v = *i;
                    if (!nodes_visited[v]) 
                    {
                        nodes_visited[v] = true;
                        queue.PB(v);
                    }
                }
            }
            reset();
        }

        void BFSmod(ll source) 
        {
            // Queue to implemnt BFS
            list<ll> queue;

            // Marking source node as visited and enqueuing
            nodes_visited[source] = true;
            queue.PB(source);

            // Queue will not be empty till all nodes reachable from source node have not been visited
            while (!queue.empty()) 
            {
                ll u = queue.front();
                cout << u << " ";
                queue.pop_front();
                // Visiting adjacency list of the dequeued node and enqueuing
                for (auto i = adj_lists[u].begin(); i != adj_lists[u].end(); ++i) 
                {
                    ll v = *i;
                    if (!nodes_visited[v]) 
                    {
                        nodes_visited[v] = true;
                        queue.PB(v);
                    }
                }
            }
        }

        // DFS algorithm
        void DFS() 
        {
            for(ll u=0;u<num_ver;++u)
            {
                if (!nodes_visited[u]) 
                {    
                    DFS_visit(u);
                }
            }
            reset();   
        }

        void connectedComponents()
        {
            // Initializing all nodes as unvisited nodes
            nodes_visited = new bool[num_ver];
            for (ll i = 0; i < num_ver; i++)
                nodes_visited[i] = false;
            int i = 1;

            for(int v = 0; v < num_ver; v++) 
            {
                if (nodes_visited[v] == false) 
                {
                    cout << "Connected Component " << i << ": ";
                    BFSmod(v);
                    i++;
                    cout << "\n";
                }
            }
        }
};