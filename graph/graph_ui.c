#include <stdio.h>
#include "graph_ui.h"
#include "graph.h"

void generateGraphOutputFile(Graph * graph) {
    FILE *fp;
    fp = fopen("./graph.dot", "w");
    struct Node * head = graph->head;
    fprintf(fp, "digraph {\n");
    while (head != NULL) {
        graph->dataPrint(fp, head->data);
        fprintf(fp,";\n");
        struct Link * link = head->successors;
        while (link != NULL) {
            graph->dataPrint(fp, head->data);
            fprintf(fp," -> ");
            graph->dataPrint(fp, link->destination->data);
            fprintf(fp,";\n");
            link = link->next;
        }
        head = head -> next;
    }
    fprintf(fp, "}\n");
    fclose(fp);
}
