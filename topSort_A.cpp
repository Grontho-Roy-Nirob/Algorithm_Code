#include <iostream>
#include <vector>
#include <stack>
#define MAX 20
using namespace std;

enum color {BLACK, GRAY, WHITE};
int nodeColor[MAX], discover_time[MAX], finish_time[MAX], time;
stack<int> topSort;

void DFS_VISIT(vector<int> G[], int u)
{
    time++;
    discover_time[u]=time;
    nodeColor[u] = GRAY;

    for(int v=0; v<G[u].size(); v++)
    {
        int adjNode= G[u][v];
        if (nodeColor[adjNode]==WHITE)
        {
            DFS_VISIT(G, adjNode);
        }
    }
     nodeColor[u] =BLACK;
     time++;
     finish_time[u]=time;
     topSort.push(u);
}

void DFS(vector<int> G[], int vertex)
{
    for(int v=1; v<=vertex; v++)
    {
        nodeColor[v]= WHITE;
    }

    time=0;
    for(int u=1; u<=vertex; u++)
    {
        if(nodeColor[u]==WHITE)
        {
            DFS_VISIT(G,u);
        }
    }
}

int main()
{
    int vertex ;
    cout <<"Enter the vertex number: ";
    cin >> vertex;

    vector <int> adjList[vertex+1];
    string NodeName[vertex+1] ={"0","105","203", "205", "215", "220", "169", "279"};

    int edge, u, v;
    cout<<"Enter the edge number: ";
    cin >> edge;

    cout <<"Enter all edges:"<<endl;
    for(int e=1 ; e<=edge; e++)
    {
        cin >> u >> v;
        adjList[u].push_back(v);
    }

     //print graph
     for(int i=1; i<=vertex; i++ )
     {
         cout<< NodeName[i]<<"--->";
         for(int j =0; j<adjList[i].size(); j++)
         {
             int index= adjList[i][j];
             cout<<NodeName[index]<<"\t";
         }
         cout<<endl;
     }

     DFS(adjList,vertex);
     cout<<"\n TopSort: ";
     while(!topSort.empty())
     {
         cout<<NodeName[topSort.top()]<<"  ";
         topSort.pop();
     }
    return 0;

}
