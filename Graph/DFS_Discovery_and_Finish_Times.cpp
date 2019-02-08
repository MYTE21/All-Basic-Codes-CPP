/**
--- DFS Discovery  and Finish Times ---
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
Start and Finish time of all nodes :
Nodes           Start Time              Finish Time
1               1                       12
2               2                       11
3               3                       10
4               4                       9
5               5                       6
6               7                       8

*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std ;

#define Max 100002
#define endl '\n'

vector<int> adj[Max] ;
bool isVisited[Max] ;
int Time ;  // Time of visiting vertexes
int start_time[Max] ;   // Start time of visiting vertex
int finish_time[Max] ;  // End time of visiting vertex

void DFS(int start)
{
    if(isVisited[start]) return ;

    isVisited[start] = true ;
    start_time[start] = Time ;
    Time++ ;

    for(int i=0;i<adj[start].size();i++)
    {
        DFS(adj[start][i]) ;
    }
    finish_time[start] = Time ;
    Time++ ;
}

int main()
{
    ios_base::sync_with_stdio(false);   // Making cin and cout as first as printf and scanf

    int nodes , edges , n1 , n2 ;

    cout<<"Total Nodes : ";
    cin>>nodes ;

    cout<<"Total Edges : ";
    cin>>edges ;

    Time = 1 ;

    cout<<"Enter connected nodes (n1 n2) : "<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>n1>>n2 ;
        adj[n1].push_back(n2) ;
        adj[n2].push_back(n1) ;
    }

    DFS(1) ;    // Starting from vertex 1

    cout<<"Start and Finish time of all nodes : "<<endl ;
    cout<<"Nodes\t\tStart Time\t\tFinish Time"<<endl ;
    for(int i=1;i<=nodes;i++)
    {
        cout<<i<<"\t\t"<<start_time[i]<<"\t\t\t"<<finish_time[i]<<endl ;
    }

    return 0 ;
}

