#include <malloc.h>
#include "graph.h"

// ======== Static methode =======

static struct Node * createNode(void * data) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) {
        perror("Error while creating a node");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    node->successors = NULL;
    node->metadata = 'r';
    return node;
}

static struct Link * createLink(struct Node * successor) {
    struct Link * link = (struct Link *) malloc(sizeof(struct Link));
    if (link == NULL) {
        perror("Error while trying to create a link");
        exit(EXIT_FAILURE);
    }
    link->next = NULL;
    link->destination = successor;
    return link;
}

static struct Node * findNode(Graph * graph, void * data) {
    struct Node * node = graph->head;
    while (node != NULL && graph->dataComp(node->data, data) != 0) {
        node = node->next;
    }
    return node;
}

static void removeLinkFromNodeByDestination(Graph * graph, struct Node * node, void * arrive) {
    struct Link * beforeLinkHead = NULL;
    struct Link * link = node->successors;
    while (link != NULL) {
        if (graph->dataComp(arrive, link->destination->data) == 0) {
            if (beforeLinkHead != NULL) {
                beforeLinkHead->next = link->next;
            } else {
                node->successors = link->next;
            }
            free(link);
            link = NULL;
            return;
        }
        beforeLinkHead = link;
        link = link->next;
    }
}

// ======== Implementation methode =======

Graph * createGraph(DataCmp dataCmp, DataFree dataFree, DataPrint dataPrint) {
    Graph * graph = (Graph*) malloc(sizeof(Graph));
    if (graph == NULL) {
        perror("Error while creating a graph");
        exit(EXIT_FAILURE);
    }
    graph->dataFree = dataFree;
    graph->dataComp = dataCmp;
    graph->dataPrint = dataPrint;
    graph->head = NULL;
    return graph;
}

void deleteGraph(Graph * graph) {
    if (graph->head != NULL) {
        struct Node * head = graph->head;
        struct Node * next = head->next;
        while (next != NULL) {
            removeNodeFromGraph(graph, head->data);
            head = next;
            next = head->next;
        }
        removeNodeFromGraph(graph, head->data);
    }
    free(graph);
    graph = NULL;
}

void addNodeToGraph(Graph * graph, void * data) {
    struct Node * new = createNode(data);
    new->next = graph->head;
    graph->head = new;
}

void removeNodeFromGraph(Graph * graph, void * data) {
    struct Node * beforeHead = NULL;
    struct Node * toDeleteNode = graph->head;
    while (toDeleteNode != NULL) {
        if (graph->dataComp(toDeleteNode->data, data) == 0) {
            break;
        }
        beforeHead = toDeleteNode;
        toDeleteNode = toDeleteNode->next;
    }
    if (toDeleteNode == NULL) return;
    while (toDeleteNode->successors != NULL) {
        removeLinkFromNodeByDestination(graph, toDeleteNode, toDeleteNode->successors->destination);
    }

    struct Node * node = graph->head;
    while (node != NULL) {
        removeLinkFromNodeByDestination(graph, node, data);
        node = node->next;
    }

    if (beforeHead != NULL) {
        beforeHead->next = toDeleteNode->next;
    } else {
        graph->head = toDeleteNode->next;
    }
    graph->dataFree(toDeleteNode->data);
    free(toDeleteNode);
    toDeleteNode = NULL;
}

void addLinkToGraph(Graph * graph, void * start, void * arrive) {
    struct Node * startNode = findNode(graph, start);
    if (startNode == NULL) {
        perror("Trying to add a link from a node that does not exist");
        exit(EXIT_FAILURE);
    }

    struct Node * arriveNode = findNode(graph, arrive);
    if (startNode == NULL) {
        perror("Trying to add a link to a node that does not exist");
        exit(EXIT_FAILURE);
    }

    struct Link * link = createLink(arriveNode);
    link->next = startNode->successors;
    startNode->successors = link;
}

void removeLinkFromGraph(Graph * graph, void * start, void * arrive) {
    struct Node * node = findNode(graph,start);
    removeLinkFromNodeByDestination(graph, node, arrive);
}
