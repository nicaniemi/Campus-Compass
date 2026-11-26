#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>

#include "data.h"
#include "loader.h"
#include "graph.h"
#include "Connection.h"

namespace
{
  std::vector<Edge> makeTestEdges()
  {
    std::vector<Edge> edges;

    Edge A{1, 2, "Hume Hall", "Graham Hall", 3};
    Edge B{1, 4, "Hume Hall", "Rawlings Hall", 2};
    Edge C{1, 50, "Hume Hall", "Jennings Hall", 4};
    Edge D{2,4,"Graham Hall" ,"Rawlings Hall" ,3};
    Edge E{2,50,"Graham Hall" ,"Jennings Hall" ,3};

    edges.push_back(A);
    edges.push_back(B);
    edges.push_back(C);
    edges.push_back(D);
    edges.push_back(E);

    return edges;
  }
}

TEST_CASE("Test 1 - Ensure properly loaded data", "[loading]")
{
  auto loaded = loadEdges("C:/Users/Nicol/CLionProjects/Campus-Connector/data/edges.csv");

  REQUIRE(loaded.size() == 72);
}

TEST_CASE("Test 2 - Verify first 5 loaded edges", "[loading]")
{
  auto edges = makeTestEdges();
  auto loaded = loadEdges("C:/Users/Nicol/CLionProjects/Campus-Connector/data/edges.csv");
  for (int i = 0; i < 5; i++)
  {
    REQUIRE(loaded[i].LocationID_1 == edges[i].LocationID_1);
    REQUIRE(loaded[i].LocationID_2 == edges[i].LocationID_2);
    REQUIRE(loaded[i].Name_1 == edges[i].Name_1);
    REQUIRE(loaded[i].Name_2 == edges[i].Name_2);
    REQUIRE(loaded[i].time == edges[i].time);
  }
}

TEST_CASE("Test 3 - Verify map built correctly", "[adjacency list]")
{
  Graph graph(makeTestEdges());

  const auto& neighbors = graph.getNeighbors(1);

  REQUIRE(neighbors.size() == 3);

  REQUIRE(neighbors[0].destinationID == 2);
  REQUIRE(neighbors[0].travelTime == 3);

  REQUIRE(neighbors[1].destinationID == 4);
  REQUIRE(neighbors[1].travelTime == 2);

  REQUIRE(neighbors[2].destinationID == 50);
  REQUIRE(neighbors[2].travelTime == 4);
}

TEST_CASE("Test 4 - Verify checkEdges function with open or DNE", "[checkEdges]")
{
  Graph graph(makeTestEdges());

  const auto& edge1 = graph.checkEdgesStatus(1, 4);
  const auto& edge2 = graph.checkEdgesStatus(1, 99);
  const auto& edge3 = graph.checkEdgesStatus(99, 1);

  REQUIRE(edge1 == "open");
  REQUIRE(edge2 == "DNE");
  REQUIRE(edge3 == "DNE");
}