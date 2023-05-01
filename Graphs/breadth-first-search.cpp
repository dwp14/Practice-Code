vector<int> BFS(Graph G, int S) {
    int size = G.getVertexCount();
    vector<bool> visited(size, false);
    list<int> queue;
    vector<int> result;
    int currentVertex;

    queue.push_front(S);
    visted(S) = true;

    while(!queue.empty()) {
        currentVertex = queue.back();
        queue.pop_back();
        result.push_back(currentVertex);
        vector<int>neighbors = G.getAdjacentVertexIDs(currentVertex);

        for(int i = 0; i < neighbors.size(); ++i) {
            int vertex = neighbors.at(i);
            if(!visited.at(vertex)) {
                queue.push_front(vertex);
                visited.at(currentVertex) = true;
            }
        }
    }
    return result;
}