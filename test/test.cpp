#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>

// uncomment and replace the following with your own headers
#include "data.h"
#include "loader.h"

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


// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
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
