#include <iostream>
#include <cstdio>
#include <vector>

#define  DFS_WHITE -1
#define  DFS_BLACK 1


using namespace std;
typedef vector<int> vi;

vector<vi> graph;
vi dfs_num;

void readGraph()    {
    string edge;
    int node1, node2;
    getline(cin, edge);

    while(getline(cin,edge))
    {
        if(edge.size() == 0)
           break;
        node1 = edge[0] - 65;
        node2 = edge[1] - 65;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
}

void dfs(int node){
    dfs_num[node] = DFS_BLACK;

    int k = graph[node].size();
    for(int c=0; c<k; c++)
        if(dfs_num[graph[node][c]] == DFS_WHITE)
          dfs(graph[node][c]);
}

int main(){
string nodes;
int casos, CC, flag=0;
scanf("%d", &casos);
for(int x=0; x<casos; x++){
    cin>>nodes;
    graph.assign(nodes[0] - 64, vi());
    dfs_num.assign(nodes[0] - 64, DFS_WHITE);
    readGraph();
    //print();
    CC = 0;
    int k = dfs_num.size();
    for(int z=0; z<k; z++)
    {
        if(dfs_num[z] == DFS_WHITE)
        {
            dfs(z);
            CC++;
        }
    }
    if(flag == 0)
       flag++;
    else
        printf("\n");
    printf("%d\n", CC);
}
return 0;
}