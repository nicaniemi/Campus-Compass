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
};




#endif // CAMPUS_COMPASS_GRAPH_H
