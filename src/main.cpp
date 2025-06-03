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
      image.set_Colour(Colour((float)x / (float)width, (float)y / (float)height, 0.f ), x, y);
    }
    
  }

  image.Export("image.bmp");
  


  return 0;
}

