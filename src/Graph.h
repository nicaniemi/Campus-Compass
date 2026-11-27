#ifndef CAMPUS_COMPASS_GRAPH_H
#define CAMPUS_COMPASS_GRAPH_H

#include <vector>
#include <unordered_map>
#include "data.h"
#include "Connection.h"

#pragma once

class Graph // Graph for all the connections between locations
{
  std::unordered_map<int, std::vector<Connection>> adjList;

public:
  Graph(const std::vector<Edge>& edges);
  const std::vector<Connection>& getNeighbors(int LocationID) const;
  std::string checkEdgesStatus(int locationID1, int locationID2) const;
  void toggleEdgesClosure(const std::vector<std::pair<int, int>>& edgePairs);
};




#endif // CAMPUS_COMPASS_GRAPH_H
