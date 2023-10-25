#include <stdbool.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirst(Graph g, int src);

int main(void) {


}




void breadthFirst(Graph g, int src) {
	bool *visited = calloc(g->nV, sizeof(bool));
	int *pred = calloc(g->nV, sizeof(int));
	Queue q = QueueNew();

	visited[src] = true;
	QueueEnqueue(q, src);
	while (!QueueIsEmpty(q)) {
		int v = QueueDequeue(q);


		printf("%d\n", v);
		for (int w = 0; w < g->nV; w++) {
			if (g->edges[v][w] && !visited[w]) {
				visited[w] = true;
				pred[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}

	free(visited);
	free(pred);
	QueueFree(q);
}