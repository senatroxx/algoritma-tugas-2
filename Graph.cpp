#include <bits/stdc++.h>
using namespace std;
 
class Graph {
  public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    void addEdge(int v, int w);
    void DFS(int v);
    void clearVisited(int v);
};
 
void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}
 
void Graph::DFS(int v)
{
  visited[v] = true;
  cout << v << " ";

  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

void Graph::clearVisited(int v)
{
  visited[v] = false;
 
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
      if (visited[*i])
          clearVisited(*i);
}
 

int main()
{
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);

  g.addEdge(1, 2);

  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(2, 4);

  g.addEdge(3, 3);
  
  g.addEdge(4, 3);

  cout << "DFS (0): " << endl;
  g.DFS(0);
  g.clearVisited(0);
  cout << endl;

  cout << "DFS (1): " << endl;
  g.DFS(1);
  g.clearVisited(1);
  cout << endl;

  cout << "DFS (2): " << endl;
  g.DFS(2);
  g.clearVisited(2);
  cout << endl;

  cout << "DFS (3): " << endl;
  g.DFS(3);
  g.clearVisited(3);
  cout << endl;

  cout << "DFS (4): " << endl;
  g.DFS(4);
  g.clearVisited(4);
  cout << endl;
 
  return 0;
}