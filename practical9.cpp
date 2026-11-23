#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int vertices, edges;

    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<pair<int, int>>> graph(vertices);

    cout << "Enter each edge as: vertex1 vertex2 weight\n";
    cout << "Use vertex numbers from 0 to " << vertices - 1 << ".\n";

    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); 
    }

    vector<bool> visited(vertices, false);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> minHeap;

    int startVertex = 0;
    minHeap.push({0, startVertex});

    int totalWeight = 0;
    int visitedCount = 0;

    while (!minHeap.empty() && visitedCount < vertices) {
        auto [weight, vertex] = minHeap.top();
        minHeap.pop();

        if (visited[vertex]) {
            continue;
        }

        visited[vertex] = true;
        totalWeight += weight;
        ++visitedCount;

        if (vertex != startVertex) {
            cout << "Included vertex " << vertex
                 << " with edge weight " << weight << '\n';
        }

        for (const auto& [neighbor, edgeWeight] : graph[vertex]) {
            if (!visited[neighbor]) {
                minHeap.push({edgeWeight, neighbor});
            }
        }
    }

    if (visitedCount != vertices) {
        cout << "The graph is disconnected, so no spanning tree exists.\n";
    } else {
        cout << "Total weight of the MST: " << totalWeight << '\n';
    }

    return 0;
}