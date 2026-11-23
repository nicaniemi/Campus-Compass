#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include "loader.h"

std::vector<Edge> loadEdges(const std::string& filename)
{
  std::ifstream file(filename); // Load the csv file

  std::vector<Edge> edges; // Vector to store all the edges of our graph

  if (file.is_open())
  {
    std::string line; // Define each line of the csv file
    std::getline(file, line); // Get header of the file (LocationID_1, LocationID_2, etc.)

    while (std::getline(file, line)) // While there is a line to read and the file is open
    {
      std::string location1 = line.substr(0, line.find(',')); // Extract LocationID_1
      int LocationID_1 = std::stoi(location1); // Change location1 to int

      // Move comma positions for parsing so next parse begins after the comma
      auto comma1 = line.find(',');
      auto comma2 = line.find(',', comma1+1);

      std::string location2 = line.substr(comma1+1, comma2-comma1-1); // Extract LocationID_2
      int LocationID_2 = std::stoi(location2); // Change location2 to int

      comma1 = line.find(',', comma1+1);
      comma2 = line.find(',', comma2+1);

      std::string Name_1 = line.substr(comma1+1, comma2-comma1-1); // Extract Name_1

      comma1 = line.find(',', comma1+1);
      comma2 = line.find(',', comma2+1);

      std::string Name_2 = line.substr(comma1+1, comma2-comma1-1); // Extract Name_2

      comma1 = line.find(',', comma1+1);

      std::string timeString = line.substr(comma1+1); // Read from 1 past last comma to end of line
      int time = stoi(timeString);

      // Create an Edge
      auto newEdge = Edge{LocationID_1, LocationID_2, Name_1, Name_2, time};
      edges.push_back(newEdge); // Push edge to vector of Edges
    }
  }

  else
  {
    throw std::invalid_argument("File was not opened properly");
  }
  return edges;
}
