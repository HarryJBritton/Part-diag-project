#ifndef DIAGRAM_H
#define DIAGRAM_H

#include<vector>
#include<Feyn/vertex.h>
#include<Feyn/connection.h>
#include<fstream>

struct DrawSettings
{
  float VertexRadius;
  float connectionWidth;


  DrawSettings();
  DrawSettings(float, float);
  ~DrawSettings();

};

class Diagram{
  public:

  Diagram();

  void add_vertex(Vertex);
  void add_vertex(int,int);
  void add_connection(Connection);
  void add_connection(int, int, int);

  int numVertices();
  int numConnections();

  Vertex get_vertex(int);
  
  void listVertices();
  void listConnections();

  // drawing functionality
  void drawVertex(int, std::ofstream&, DrawSettings&);
  void drawAllVertices(std::ofstream&, DrawSettings&);

  void drawConnection(Connection, std::ofstream&, DrawSettings&);
  void drawAllConnections(std::ofstream&, DrawSettings&);



  private:

    std::vector<Connection> connections;
    std::vector<Vertex> vertices;

};

#endif