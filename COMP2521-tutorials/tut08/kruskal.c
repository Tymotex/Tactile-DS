Graph kruskalFindMST(Graph g) {
	Graph mst = GraphNew();
	Edge eList[g->nV]; 
    edges(eList, g->nE, g);

    // Sort the edges into increasing order of weight
	sortEdgeList(eList, g->nE);
	
    // Go down the list of cheapest edges and include them in the MST
    for (int i = 0; mst->nE < g->nV - 1; i++) {
		Edge e = eList[i];
		GraphAddEdge(mst, e);
        // ...?       
	}
	return mst;
}
