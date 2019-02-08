/**
--- Topological Sorting ---
Time Complexity: Time complexity is same as DFS which is O(V+E).

input :
Enter nodes number : 7
Enter edges number : 10
Enter all connected nodes (n1->n2) :
1 3
1 4
3 6
4 6
4 3
2 4
2 5
5 4
4 7
5 7
output :
Works sequences : 2 --> 5 --> 1 --> 4 --> 7 --> 3 --> 6
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define Max 100002
#define endl '\n'

vector<int> Graph[Max] ;    // Nodes and their connections
vector<int> Store ; // Store the sequences of works
bool Color[Max] ;
int nodes , edges , n1 , n2 ;

/*
    DFS function
*/
void DFS(int x)
{
    Color[x] = true ;   // If visited

    for(int i=0;i<Graph[x].size();i++)
    {
        int u = Graph[x][i] ;

        if(!Color[u])
        {
            DFS(u) ;
        }
    }
    Store.push_back(x) ;
}

/*
    Topological Sort Function
*/
void Topological_Sort()
{
    for(int i=1;i<=nodes;i++)
    {
        if(!Color[i])
        {
            DFS(i) ;
        }
    }
}

int main()
{
    cout<<"Enter nodes number : ";
    cin>>nodes ;
    cout<<"Enter edges number : ";
    cin>>edges ;

    cout<<"Enter all connected nodes (n1->n2): "<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>n1>>n2 ;
        Graph[n1].push_back(n2) ;   // As it is Directed Acyclic Graph (DAG) - It has directions from nodes to nodes
    }

    Topological_Sort() ;    // Function Call

    cout<<"Works sequences : " ;
    for(int i=Store.size()-1;i>=0;i--)
    {
        cout<<Store[i] ;
        if(i!=0) cout<<" --> ";
    }
    cout<<endl ;

    return 0;
}


