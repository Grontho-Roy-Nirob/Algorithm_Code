#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair< int, pair<int,int> > > G ;// w ,u, v,
vector <pair< int ,pair<int,int> > > MST; //w, u, v
int vertex, edge;
int *parent;

void make_set()
{
    parent= new int [vertex];
    for (int i =0; i<vertex; i++)
        parent[i]=i;
}
void print_parent()
{
    cout<<endl;
    for (int i =0; i<vertex; i++)
        cout<<parent[i]<<"\t";
}

int find_set(int u)
{
    if(u == parent[u])
        return u;
    else
        return find_set(parent[u]);
}

void union_set(int u, int v)
{
    parent[u] = parent[v];
}


int main()
{
    cout<<"No of Vertex: "<<vertex;
    cin >> vertex;

    cout<< "No of edges: "<<edge;
    cin>> edge;

    int u,v,w;
    cout <<"Enter edge with weight:"<<endl;
    for(int i=1; i<=edge; i++)
    {
        cin>> u>> v>>w;
        G.push_back(make_pair(w,make_pair(u,v)));
    }

    cout<<"\nPrint the graph:"<<endl;
    cout<< "Edge:   "<< " Weight"<< endl;
    for (int i =0 ; i<G.size(); i++)
    {
        cout<< "("<< G[i].second.first<< ", " <<G[i].second.second<< ")"<< ": "<<G[i].first<<endl;
    }

    // Kruskal

    make_set();
    print_parent();
    // sort edge wrt weight
    sort(G.begin(), G.end());
    cout<<"\nPrint sorted graph:"<<endl;
    cout<< "Edge:   "<< " Weight"<< endl;
    for (int i =0 ; i<G.size(); i++)
    {
        cout<< "("<< G[i].second.first<< ", " <<G[i].second.second<< ")"<< ": "<<G[i].first<<endl;
    }

    int u_loc, v_loc;
    for(int i=0; i<edge; i++)
    {
        u_loc= find_set(G[i].second.first);
        v_loc= find_set(G[i].second.second);
        if(u_loc != v_loc)
        {
            MST.push_back(G[i]);
            union_set(u_loc, v_loc);
            cout<<"\nParent array after taking edge :("<< G[i].second.first<< ", " <<G[i].second.second<< ")"<< ": "<<G[i].first<<endl;
            print_parent();
        }
    }

    //print MST
    int sum = 0;
    cout <<"\n\nMST:"<<endl;
    cout<< "Edge:   "<< " Weight"<< endl;
    for (int i =0 ; i<MST.size(); i++)
    {
        cout<< "("<< MST[i].second.first<< ", " <<MST[i].second.second<< ")"<< ": "<<MST[i].first<<endl;
        sum +=MST[i].first;
    }
    cout<<"\nTotal weight =" <<sum<<endl;



  return 0;
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7


*/

