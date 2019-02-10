/*
-------------------------------------
Strongly Connected Components (SCC) :
-------------------------------------
A directed graph is strongly connected if there is a path between all pairs of vertices.
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
------
input:
------
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
-------
output:
-------
Numbers of Strongly Connected Components are : 3
(1) - 1 3 2 
(2) - 4 
(3) - 5 7 6
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
 
#define Max 100001
 
vector<int> Graph[Max] ;
vector<int> Graph_REVERSE[Max] ;
stack<int> Stack ;  // Storing finishing nodes sequences
bool isVisited[Max] ;
vector<int> Results[Max] ;  // For storing all SCC
 
int nodes ; // Number of nodes
int edges ; // Number of edges
int comp ;  // This holds the components strongly connex;
 
void readData()
{
    int x ;
    int y;
 
    cin>>nodes>>edges ;
 
    for(int i=1;i<=edges;i++)
    {
        cin>>x>>y ;
        Graph[x].push_back(y);
        Graph_REVERSE[y].push_back(x);
    }
}
 
/*
    for debug
*/
void printGraph()
{ 
    for(int i=1;i<=nodes;i++)
    {
        cout<<i<<" -> " ;
 
        for(int v=0;v<Graph[i].size();v++)
        {
            int u = Graph[i][v] ;
            cout<<u<<" " ;
        }
        cout<<endl ;
    }
}
 
/*
    for debug
*/
void printReverseGraph()
{ 
    for(int i=1;i<=nodes;i++)
    {
        cout<<i<<" -> " ;

        for(int v=0;v<Graph_REVERSE[i].size();v++)
        {
            int u = Graph_REVERSE[i][v] ;
            cout<<u<<" " ;
        }
        cout<<endl ;
    }
}
 
void DFS(int node)
{ 
    isVisited[node] = 1 ;
 
    for(int i=0;i<Graph[node].size();i++)
    {
        int u = Graph[node][i] ;
        if(!isVisited[u])
        {
            DFS(u) ;
        }
    }
 
    Stack.push(node) ;
}
 
 
void DFS_REVERSE(int node)
{
    isVisited[node] = 1 ;
 
    Results[comp].push_back(node);
 
    for(int i=0;i<Graph_REVERSE[node].size();i++)
    {
        int u = Graph_REVERSE[node][i] ;
 
        if(!isVisited[u])
        {
            DFS_REVERSE(u) ;
        }
    }
}
 
/*
    for debug
*/
void printStack()
{
    cout<<endl ;
 
    while(!Stack.empty())
    {
        cout<<Stack.top()<<" " ;
        Stack.pop();
    }
}
 
void Kosaraju()
{
 
     int vertex = 0 ;
 
    for(int i = 1; i <= nodes; i++)
    {
        if(!isVisited[i])
        {
            DFS(i) ;
        }
    }
 
    memset(isVisited, 0, sizeof(isVisited)) ;
 
    while(!Stack.empty())
    {
 
        vertex = Stack.top();
 
        Stack.pop();
 
        if(!isVisited[vertex])
        {
            comp++;
 
            DFS_REVERSE( vertex );
        }
    }
}
 
void writeData()
{
    cout<<"Numbers of Strongly Connected Components are : "<<comp<<endl ;
 
    for(int i=1;i<=comp;i++)
    {
        cout<<"("<<i<<") - " ;

        for(int v=0;v<Results[i].size();v++)
        {
            int u = Results[i][v] ;
            cout<<u<<" " ;
        }
        cout<<endl ;
    }
    cout<<endl ;
}
 
int main()
{
    readData(); // Input Function
    Kosaraju(); // SCC  generating Function
    writeData();    // Output Function
 
    return 0;
}
