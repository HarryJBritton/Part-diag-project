#include<Feyn/diagram.h>
#include<iostream>
#include<algorithm>

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
void Diagram::drawVertex(int ID, Image& image, DrawSettings & settings)
{
  Vertex v = get_vertex(ID);
  int x_pos = v.get_pos()[0];
  int y_pos = v.get_pos()[1];

  for (int y = 0; y < image.get_height(); y++)
  {
    for (int x = 0; x < image.get_width(); x++)
    {
      if((float)(x - x_pos) * (float)(x - x_pos) + (float)(y - y_pos) * (float)(y - y_pos) < settings.VertexRadius)
      {
        Colour current_colour = image.get_Colour(x,y);
        Colour new_colour = Colour(std::min(current_colour.r, settings.vertexColour.r),
          std::min(current_colour.g, settings.vertexColour.g),
          std::min(current_colour.b, settings.vertexColour.b));

        image.set_Colour(new_colour, x, y);
        
      }
    }
  }
}

void Diagram::drawAllVertices(Image & image, DrawSettings & settings)
{
  for (auto it = vertices.begin(); it < vertices.end(); it++)
  {
    drawVertex(it->get_ID(), image, settings);
  }
  
}

void Diagram::drawConnection(Connection connection, Image & image, DrawSettings & settings)
{
  Vertex v1 = get_vertex(connection.get_startID());
  Vertex v2 = get_vertex(connection.get_endID());

  


}

void Diagram::drawAllConnections(Image & image, DrawSettings & settings)
{
  // iterate over connections
  for(auto it = connections.begin(); it < connections.end(); it++)
  {
    drawConnection(*it, image, settings);
  }


}


DrawSettings::DrawSettings()
  : VertexRadius(10), vertexColour(Colour(1.f, 0.0f, 0.0f))
{
}

DrawSettings::DrawSettings(float radius, Colour colour)
  : VertexRadius(radius), vertexColour(colour)
{
}

DrawSettings::~DrawSettings()
{
}
