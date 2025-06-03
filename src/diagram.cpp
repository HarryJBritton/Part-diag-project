#include<Feyn/diagram.h>
#include<iostream>
#include<algorithm>
#include<fstream>


Diagram::Diagram(){
  connections = std::vector<Connection>();
  vertices = std::vector<Vertex>();
}

void Diagram::add_vertex(Vertex v)
{
  // TODO: check no duplicate or same pos

  vertices.push_back(v);
}
void Diagram::add_vertex(int positionX, int positionY)
{

  vertices.push_back(Vertex(positionX,positionY));
}

void Diagram::add_connection(Connection c)
{
  connections.push_back(c);
}
void Diagram::add_connection(int start, int end, int connectionType)
{
  connections.push_back(Connection(start, end, connectionType));
}

int Diagram::numVertices()
{
  return vertices.size();
}
int Diagram::numConnections()
{
  return connections.size();
}

Vertex Diagram::get_vertex(int ID)
{
    for(auto it = vertices.begin(); it < vertices.end(); it++)
  {
    if(it->get_ID() == ID)
    {
      return *it;
    }
  }
  std::cout<<"No vertex with that ID found\n";
  return Vertex();
}

void Diagram::listVertices(){


  for(auto it = vertices.begin(); it < vertices.end(); it++)
  {
    std::cout<<it->get_ID()<<" at ["<<it->get_pos().at(0)<<", "<<it->get_pos().at(1)<<"]"<<std::endl;
  }
  

}
void Diagram::listConnections()
{
    for(auto it = connections.begin(); it < connections.end(); it++)
  {
    std::cout<<"Type "<<it->get_type()<<" from "<<it->get_startID()<<" to "<<it->get_endID()<<std::endl;
  }
}
void Diagram::drawVertex(int ID, std::ofstream& file, DrawSettings & settings)
{
  Vertex v = get_vertex(ID);
  int x_pos = v.get_pos()[0];
  int y_pos = v.get_pos()[1];

  file << "  <circle cx=\""<<x_pos<<"\" cy=\""<<y_pos<<"\" r=\""<<settings.VertexRadius<<"\" fill=\"black\" />\n";


  
}

void Diagram::drawAllVertices(std::ofstream & file, DrawSettings & settings)
{
  for (auto it = vertices.begin(); it < vertices.end(); it++)
  {
    drawVertex(it->get_ID(), file, settings);
  }
  
}

void Diagram::drawConnection(Connection connection, std::ofstream & file, DrawSettings & settings)
{
  Vertex v1 = get_vertex(connection.get_startID());
  Vertex v2 = get_vertex(connection.get_endID());

  int x1 = v1.get_pos()[0];
  int y1 = v1.get_pos()[1];

  int x2 = v2.get_pos()[0];
  int y2 = v2.get_pos()[1];

  file << "<line x1=\""<<x1<<"\" y1=\""<<y1<<"\" x2=\""<<x2<<"\" y2=\""<<y2<<"\" style=\"stroke:red;stroke-width:"<<settings.connectionWidth<<"\" />";
  
}

void Diagram::drawAllConnections(std::ofstream & file, DrawSettings & settings)
{
  // iterate over connections
  for(auto it = connections.begin(); it < connections.end(); it++)
  {
    drawConnection(*it, file, settings);
  }


}


DrawSettings::DrawSettings()
  : VertexRadius(10), vertexColour(Colour(1.f, 0.0f, 0.0f)), connectionWidth(5)
{
}

DrawSettings::DrawSettings(float radius, Colour colour, float width)
  : VertexRadius(radius), vertexColour(colour), connectionWidth(width)
{
}

DrawSettings::~DrawSettings()
{
}
