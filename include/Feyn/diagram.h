#ifndef DIAGRAM_H
#define DIAGRAM_H

#include<vector>
#include<Feyn/vertex.h>
#include<Feyn/connection.h>

class Diagram{
  public:

  Diagram();

  void add_vertex(Vertex);
  void add_vertex(int,int);
  void add_connection(Connection);
  void add_connection(int, int, int);

  int numVertices();
  int numConnections();

  void listVertices();
  void listConnections();

  private:

    std::vector<Connection> connections;
    std::vector<Vertex> vertices;

};

#endif