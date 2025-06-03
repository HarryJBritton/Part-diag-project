#include<Feyn/diagram.h>
#include<iostream>

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