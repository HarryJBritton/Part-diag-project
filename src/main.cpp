#include<Feyn/vertex.h>
#include<Feyn/connection.h>
#include<Feyn/diagram.h>
#include<Image/image.h>
#include<iostream>

int main()
{
  std::cout<<"\nHello world!\n";

  const int width = 640;
  const int height = 480;

  Image image(width,height);

  for (int y = 0; y < height; y++)
  {
    for (int x = 0; x < width; x++)
    {
      image.set_Colour(Colour(1.f,1.f,1.f), x, y);
    }
    
  }

  Diagram d;

  d.add_vertex(20,20);
  d.add_vertex(500,50);
  d.add_vertex(250, 400);

  DrawSettings settings;

  d.drawAllVertices(image, settings);


  image.Export("image.bmp");
  


  return 0;
}

