/**
--- DFS (Depth First Search) Basic Code ---
Time Complexity: Time complexity is O(V+E).

input:
Total Nodes : 6
Total Edges : 7
Enter connected nodes (n1 n2) :
1 2
1 5
2 3
2 5
3 4
4 5
4 6
output:
Path : 1 2 3 4 5 6

*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std ;

#define Max 100002
#define endl '\n'

vector<int> adj[Max] ;
bool isVisited[Max] ;

void DFS(int start)
{
    if(isVisited[start]) return ;

    isVisited[start] = true ;
    cout<<start<<" ";

    for(int i=0;i<adj[start].size();i++)
    {
        DFS(adj[start][i]) ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);   // Making cin and cout as first as printf and scanf

    int nodes , edges , n1 , n2 ;

    cout<<"Total Nodes : ";
    cin>>nodes ;

    cout<<"Total Edges : ";
    cin>>edges ;

    cout<<"Enter connected nodes (n1 n2) : "<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>n1>>n2 ;
        adj[n1].push_back(n2) ;
        adj[n2].push_back(n1) ;
    }

    cout<<"Path : ";
    DFS(1) ;    //Starting from vertex 1

    return 0 ;
}

