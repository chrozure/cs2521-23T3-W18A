#ifndef GRAPH_H
#define GRAPH_H

struct graph {
    int nV;
    int **edges;
};

typedef struct graph *Graph;

Graph GraphNew();

void GraphFree();

#endif