#include<iostream>
#include <bits/stdc++.h>

typedef long long ll;
#define PB push_back
const ll INF =1e9;

using namespace std;

// Weighted Directed Graph
class Graph 
{
    ll num_of_vertices;
    list<pair<ll,ll>> *pAdjLists;

    private:
        // Find Weight of edge (tail, head)
        ll Weight(ll tail, ll head)
        {
            if(tail==head)
            {
                return 0;
            }
            list<pair<ll,ll>> adj_list = pAdjLists[tail];
            for (auto neighbor=adj_list.begin();neighbor!=adj_list.end(); ++neighbor)
            {
                if (neighbor->first==head)
                {
                    return neighbor->second;
                }
            }
            return INF;
        }

    public:
        // Create an undirected graph with given vertices and maintain adjacency list
        Graph(ll node_count) 
        {
            num_of_vertices = node_count;
            pAdjLists = new list<pair<ll,ll>>[num_of_vertices];
        }
        // Add edges to the graph
        void AddEdges(ll tail, ll head, ll weight) 
        {
            pAdjLists[tail].PB(make_pair(head, weight));
        }
        void Djikastra(ll source)
        {
            // Init single source
            vector<ll> distance(num_of_vertices, INF);
            vector<ll> predecessor(num_of_vertices,-1);
            distance[source] = 0;
            
            // Implementation of min heap using priority queue
            priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;

            pq.push(make_pair(distance[source], source));
            while(!pq.empty())
            {
                ll u = pq.top().second;
                pq.pop();
                list<pair<ll,ll>> adj_list = pAdjLists[u];
                for (auto i=adj_list.begin(); i!=adj_list.end(); ++i)
                {
                    ll v = i->first;
                    ll weight = i->second;
                    // Relax Function used to update shortest distances across edges
                    if(distance[v]>distance[u]+weight)
                    {
                        distance[v] = distance[u] + weight;
                        predecessor[v] = u;
                        pq.push(make_pair(distance[v], v));
                    }
                    
                }
            }
            cout << "Djikastra Shortest Path" << endl;
            for(ll vertex=0; vertex<num_of_vertices; ++vertex)
            {
                if(vertex !=source)
                {
                    cout << vertex << ": " << distance[vertex] << ", " << predecessor[vertex] << endl;
                }
            }
        }

        bool BellmanFord(ll source)
        {
            // Init single source
            vector<ll> distance(num_of_vertices, INF);
            vector<ll> predecessor(num_of_vertices,-1);
            distance[source] = 0;
            // Relaxing all edges at least |V|-1 times
            for(ll i=1;i<=num_of_vertices-1;++i)
            {
                for(ll u=0;u<num_of_vertices;++u)
                {
                    list<pair<ll,ll>> adj_list = pAdjLists[u];
                    for (auto i=adj_list.begin();i!=adj_list.end(); ++i)
                    {
                        ll v = i->first;
                        ll weight = i->second;
                        // Relax Function used to update shortest distances across edges
                        if(distance[v]>distance[u]+ weight)
                        {
                            distance[v] = distance[u] + weight;
                            predecessor[v] = u;
                        }    
                    }
                }
            }
            for(ll u=0;u<num_of_vertices;++u)
            {
                list<pair<ll,ll>> adj_list = pAdjLists[u];
                for (auto i=adj_list.begin(); i!=adj_list.end(); ++i)
                {
                    ll v = i->first;
                    ll weight = i->second;
                    // Checking for Negative Weight cycle
                    if(distance[v]>distance[u]+ weight)
                    {
                        return false;
                    }    
                }
            }
            cout << "Bellman Ford Shortest Path" << endl;
            for(ll vertex=0; vertex < num_of_vertices; ++vertex)
            {
                if(vertex !=source)
                {
                    cout << vertex << ": " << distance[vertex] << ", " << predecessor[vertex] << endl;
                }
            }
            return true;
        }
        void FloydWarshall()
        {
            vector<ll> row(num_of_vertices,INF);
            vector<vector<ll>> temp(num_of_vertices,row),final(num_of_vertices,row);
            for(ll i=0;i<num_of_vertices;++i)
            {
                for(ll j=0;j<num_of_vertices;++j)
                {
                    temp[i][j] = Weight(i,j);
                }
            }
            final = temp;
            for(ll k=1;k<=num_of_vertices;++k)
            {
                temp = final;
                for(ll i=0;i<num_of_vertices;++i)
                {
                    for(ll j=0;j<num_of_vertices;++j)
                    {
                        final[i][j] = min(temp[i][j],temp[i][k-1]+temp[k-1][j]);
                    }
                }
            }
            cout << "Floyd-Warshall Shortest Paths"<<endl;
            cout << "  ";
            for(ll i=0;i<num_of_vertices;++i)
            {
                cout << i << " ";
            }
            cout << endl;
            for(ll i=0;i<num_of_vertices;++i)
            {
                cout << i << " ";
                for(ll j=0;j<num_of_vertices;++j)
                {
                    if (final[i][j]>=INF-1e5) cout << "i" << " ";
                    else cout << final[i][j] << " ";
                }
                cout << endl;
            }
        }
};

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