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
void Diagram::add_vertex(float positionX, float positionY)
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
void Diagram::drawVertex(int ID, std::ofstream& file, float scaleX, float scaleY, float radius)
{
  Vertex v = get_vertex(ID);
  int x_pos = v.get_pos()[0] * scaleX;
  int y_pos = v.get_pos()[1] * scaleY;

  file << "  <circle cx=\""<<x_pos<<"\" cy=\""<<y_pos<<"\" r=\""<<radius<<"\" fill=\"red\" />\n";


  
}

void Diagram::drawAllVertices(std::ofstream & file, DrawSettings & settings)
{
  float maxX = 0, maxY = 0;


  for (auto it = vertices.begin(); it < vertices.end(); it++)
  {
    if (it->get_pos()[0] > maxX)
    {
      maxX = it->get_pos()[0];
    }

    if (it->get_pos()[1] > maxY)
    {
      maxY = it->get_pos()[1];
    }
    
  }


  for (auto it = vertices.begin(); it < vertices.end(); it++)
  {
    drawVertex(it->get_ID(), file, settings.diagramWidth / ((float) maxX + 1.0f), settings.diagramHeight / ((float) maxY + 1.0f), settings.VertexRadius);
  }
  
}

void Diagram::drawConnection(Connection connection, std::ofstream & file, float scaleX, float scaleY, float width )
{
  Vertex v1 = get_vertex(connection.get_startID());
  Vertex v2 = get_vertex(connection.get_endID());

  int x1 = v1.get_pos()[0] * scaleX;
  int y1 = v1.get_pos()[1] * scaleY;

  int x2 = v2.get_pos()[0] * scaleX;
  int y2 = v2.get_pos()[1] * scaleY;

  file << "<line x1=\""<<x1<<"\" y1=\""<<y1<<"\" x2=\""<<x2<<"\" y2=\""<<y2<<"\" style=\"stroke:red;stroke-width:"<<width<<"\" />";
  
}

void Diagram::drawAllConnections(std::ofstream & file, DrawSettings & settings)
{

  float maxX = 0, maxY = 0;
  for (auto it = vertices.begin(); it < vertices.end(); it++)
  {
    if (it->get_pos()[0] > maxX)
    {
      maxX = it->get_pos()[0];
    }

    if (it->get_pos()[1] > maxY)
    {
      maxY = it->get_pos()[1];
    }
    
  }

  // iterate over connections
  for(auto it = connections.begin(); it < connections.end(); it++)
  {
    drawConnection(*it, file,
      settings.diagramWidth / (maxX + 1.0f),
      settings.diagramHeight / (maxY + 1.0f), 
      settings.connectionWidth);
  }


}

void Diagram::sortVert()
{
  // Note HERE that this relies on the index and ID being the same
  // make vectors for from and to count

  int fromCount[vertices.size()] = {0};
  int toCount[vertices.size()] = {0};

  // count the number of from and too points
  for (auto it = connections.begin(); it < connections.end(); it++)
  {
    fromCount[it->get_startID()] ++;
    toCount[it->get_endID()]++;
  }

  // find start points and un-connected points
  int currentStartY = 1;

  for (int index = 0; index < vertices.size(); index++)
  {
    if (fromCount[index] == 0 && toCount[index] == 0)
    {
      std::cout<<"ERR: vertex ID: "<<index<<" has no connections and so cannot be drawn.\n";
      vertices.at(index).set_pos(0, 0);

    }
    else if (toCount == 0)
    {
      vertices.at(index).set_pos(1, currentStartY);
      currentStartY ++;
    }
  }
  

}


DrawSettings::DrawSettings()
  : VertexRadius(10), connectionWidth(5), diagramWidth(200), diagramHeight(200)
{
}

DrawSettings::DrawSettings(float radius, float lineWidth, float dWidth, float dHeight)
  : VertexRadius(radius), connectionWidth(lineWidth), diagramWidth(dWidth), diagramHeight(dHeight)
{
}

DrawSettings::~DrawSettings()
{
}
