#include <stdio.h>
#include "graph/graph.h"
#include "data/my_data_structure.h"
#include "graph/graph_ui.h"


void populateGraph(Graph * graph) {
    MyDataStructure * myDataStructure[10];
    for (int i = 0; i < 10; ++i) {
        myDataStructure[i] = createMyDataStructure(i);
        addNodeToGraph(graph, myDataStructure[i]);
    }

    addLinkToGraph(graph, myDataStructure[0], myDataStructure[0]);
    addLinkToGraph(graph, myDataStructure[0], myDataStructure[5]);
    addLinkToGraph(graph, myDataStructure[0], myDataStructure[9]);

    addLinkToGraph(graph, myDataStructure[1], myDataStructure[2]);
    addLinkToGraph(graph, myDataStructure[1], myDataStructure[3]);
    addLinkToGraph(graph, myDataStructure[1], myDataStructure[8]);

    addLinkToGraph(graph, myDataStructure[2], myDataStructure[3]);
    addLinkToGraph(graph, myDataStructure[2], myDataStructure[1]);
    addLinkToGraph(graph, myDataStructure[2], myDataStructure[7]);

    addLinkToGraph(graph, myDataStructure[3], myDataStructure[7]);
    addLinkToGraph(graph, myDataStructure[3], myDataStructure[9]);
    addLinkToGraph(graph, myDataStructure[3], myDataStructure[3]);

    addLinkToGraph(graph, myDataStructure[4], myDataStructure[7]);
    addLinkToGraph(graph, myDataStructure[4], myDataStructure[9]);
    addLinkToGraph(graph, myDataStructure[4], myDataStructure[3]);

    addLinkToGraph(graph, myDataStructure[5], myDataStructure[0]);
    addLinkToGraph(graph, myDataStructure[5], myDataStructure[5]);
    addLinkToGraph(graph, myDataStructure[5], myDataStructure[9]);

    addLinkToGraph(graph, myDataStructure[6], myDataStructure[2]);
    addLinkToGraph(graph, myDataStructure[6], myDataStructure[3]);
    addLinkToGraph(graph, myDataStructure[6], myDataStructure[8]);

    addLinkToGraph(graph, myDataStructure[7], myDataStructure[3]);
    addLinkToGraph(graph, myDataStructure[7], myDataStructure[1]);
    addLinkToGraph(graph, myDataStructure[7], myDataStructure[7]);

    addLinkToGraph(graph, myDataStructure[8], myDataStructure[7]);
    addLinkToGraph(graph, myDataStructure[8], myDataStructure[9]);
    addLinkToGraph(graph, myDataStructure[8], myDataStructure[3]);

    addLinkToGraph(graph, myDataStructure[9], myDataStructure[7]);
    addLinkToGraph(graph, myDataStructure[9], myDataStructure[9]);
    addLinkToGraph(graph, myDataStructure[9], myDataStructure[3]);
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
