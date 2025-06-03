#include<Feyn/vertex.h>
#include<Feyn/connection.h>
#include<Feyn/diagram.h>
#include<Image/image.h>
#include<iostream>
#include<fstream>

int main()
{
  std::cout<<"\nHello world!\n";

  Diagram d;

  d.add_vertex(150, 115);
  d.add_vertex(50,50);
  d.add_vertex(100, 100);

  d.add_connection(1,2,1);
  d.add_connection(2,3,1);

  DrawSettings settings;


  
  std::ofstream file("output.svg");
  if (!file.is_open()) return 1;

  file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
  file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"200\" height=\"200\">\n";


  d.drawAllVertices(file, settings);
  d.drawAllConnections(file,settings);


  file << "</svg>\n";

  file.close();


  return 0;
}

