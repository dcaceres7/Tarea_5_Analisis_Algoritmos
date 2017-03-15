#include <iostream>
#include "Edge.h"
#include "Test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

map<int,bool> vis;

bool ciclo(int** graph, int size, int actual, int father)
{
    if(vis[actual])
        return true;

    vis[actual]=true;

    for(int i=0;i<size;i++)
        if(graph[actual][i]!=-1 && i!=father)
            if(ciclo(graph,size,i,actual))
                return true;

    vis[actual]=false;

    return false;
}

bool ciclo(int** graph, int size)
{
    for(int i=0;i<size;i++)
        vis[i]=false;

    for(int i=0;i<size;i++)
    {
        if(ciclo(graph,size,i,0))
            return true;
    }

    return false;
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    int **res = new int* [size];
    for(int i=0;i<size;i++)
    {
        res[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            res[i][j]=-1;
        }
    }

    for(int i =0; i<edges.size();i++)
    {
        res[edges[i]->source][edges[i]->destination] = edges[i]->weight;
        res[edges[i]->destination][edges[i]->source] = edges[i]->weight;
        if(ciclo(res,size))
        {
           res[edges[i]->source][edges[i]->destination] = -1;
           res[edges[i]->destination][edges[i]->source] = -1;
        }
    }

    return res;
}

int main ()
{

    test();
    return 0;
}
