#include<Feyn/vertex.h>
#include<Feyn/connection.h>
#include<Feyn/diagram.h>
#include<iostream>

int main()
{
  std::cout<<"\nHello world!\n";

  Diagram d = Diagram();

  d.add_vertex(0,0);
  d.add_vertex(1,2);
  d.add_connection(1,2,1);


  std::cout<<d.numVertices()<<" vertices with ";
  std::cout<<d.numConnections()<<" connections"<<std::endl;

  d.listVertices();
  d.listConnections();


  return 0;
}

