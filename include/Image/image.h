#ifndef IMAGE_H
#define IMAGE_H

#include<vector>

struct Colour
{
  float r,g,b;

  Colour();
  Colour(float r, float g, float b);
  ~Colour();
};

class Image
{
public:
  Image(int width, int height);
  ~Image();

  Colour get_Colour(int x, int y) const;
  void set_Colour(const Colour& colour, int x, int y);

  void Export(const char* path) const;

private:
  int m_width;
  int m_height;
  std::vector<Colour> m_colours;

};


#endif