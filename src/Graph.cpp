#include <vector>
#include "Graph.h"

Graph::Graph(const std::vector<Edge>& edges) // Create the graph of all the roads
{
  for (const auto& edge : edges)
  {
    auto& start = adjList[edge.LocationID_1];
    start.push_back({edge.LocationID_2, edge.time});
  }
}

const std::vector<Connection>& Graph::getNeighbors(int LocationID) const // Return the neighbors of a specified location
{
  return adjList.at(LocationID);
}

std::string Graph::checkEdgesStatus(int locationID1, int locationID2) const
{
  if (adjList.find(locationID1) != adjList.end())
  {
    const auto& neighbors = getNeighbors(locationID1);
    for (auto& neighbor : neighbors)
    {
      if (neighbor.destinationID == locationID2)
      {
        if (neighbor.isOpen == true)
        {
          return "open";
        }
        else
        {
          return "closed";
        }
      }
    }
  }
  return "DNE";
}