#include "Graph.h"

Graph::Graph(const std::vector<Edge>& edges) // Create the graph of all the roads
{
  for (const auto& edge : edges)
  {
    auto& start = adjList[edge.LocationID_1];
    start.push_back({edge.LocationID_2, edge.time});
  }
}
