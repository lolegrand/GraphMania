#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph/graph.h"
#include "data/my_data_structure.h"
#include "graph/graph_ui.h"


void populateGraph(Graph * graph) {
    MyDataStructure * myDataStructure[10];
    for (int i = 0; i < 10; ++i) {
        myDataStructure[i] = createMyDataStructure(i);
        addNodeToGraph(graph, myDataStructure[i]);
    }
    srand(time(NULL));
    for (int i = 0; i < 30; ++i) {
        addLinkToGraph(graph, myDataStructure[rand() % 10], myDataStructure[rand() % 10]);
    }
}

int main() {
    Graph* graph = createGraph(
            (DataCmp) compareMyDataStructure,
            (DataFree) freeMyDataStructure,
            (DataPrint) printMyDataStructure
            );

    populateGraph(graph);

    generateGraphOutputFile(graph);

    deleteGraph(graph);

    return 0;
}
