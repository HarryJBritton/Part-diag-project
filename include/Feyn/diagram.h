#ifndef DIAGRAM_H
#define DIAGRAM_H

#include<vector>
#include<Feyn/vertex.h>
#include<Feyn/connection.h>
#include<Image/image.h>

struct DrawSettings
{
  float VertexRadius;
  Colour vertexColour;

  DrawSettings();
  DrawSettings(float, Colour);
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
  void drawVertex(int, Image&, DrawSettings&);
  void drawAllVertices(Image&, DrawSettings&);

  void drawConnection(Connection, Image&, DrawSettings&);
  void drawAllConnections(Image&, DrawSettings&);



  private:

    std::vector<Connection> connections;
    std::vector<Vertex> vertices;

};

#endif