#ifndef CAMPUS_COMPASS_CONNECTION_H
#define CAMPUS_COMPASS_CONNECTION_H

struct Connection // All the connections between 2 points
{
  int destinationID;
  int travelTime;
  bool isOpen = true;
};

#endif // CAMPUS_COMPASS_CONNECTION_H
