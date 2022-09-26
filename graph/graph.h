#ifndef GRANDELIA_GRAPH_H
#define GRANDELIA_GRAPH_H

#include <stdint.h>

typedef int (*DataCmp)(const void *, const void *);

typedef int (*DataFree)(void *);

typedef int (*DataPrint)(FILE * file, void *);

struct Node {
    void * data;
    struct Node * next;
    struct Link * successors;
    union {
        struct {
            unsigned int is_visited : 1;
            unsigned int is_main_path : 1;
        };
        unsigned int _;
    };
};

struct Link {
    struct Node * destination;
    struct Link * next;
};

typedef struct {
    struct Node * head;
    DataCmp dataComp;
    DataFree dataFree;
    DataPrint dataPrint;
} Graph;

Graph * createGraph(DataCmp dataComp, DataFree dataFree, DataPrint dataPrint);

void deleteGraph(Graph * graph);

void addNodeToGraph(Graph * graph, void * data);

void removeNodeFromGraph(Graph * graph, void * data);

void addLinkToGraph(Graph * graph, void * start, void * arrive);

void removeLinkFromGraph(Graph * graph, void * start, void * arrive);

void breadthFirstSearch(Graph * graph, void * start, void * arrive);

void deepFirstSearch(Graph * graph, void * start, void * arrive);

// Algorithm

Graph * royWarshall(Graph * graph);

Graph * marimont(Graph * graph);

Graph * foulkes(Graph * graph);

#endif //GRANDELIA_GRAPH_H
