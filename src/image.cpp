#include<Image/image.h>
#include<iostream>
#include<fstream>

Image::Image(int width, int height)
  :m_width(width), m_height(height), m_colours(std::vector<Colour>(width*height))
{
}

Image::~Image()
{
}

Colour Image::get_Colour(int x, int y) const
{
  return m_colours[y* m_width + x];
}

void Image::set_Colour(const Colour &colour, int x, int y)
{
  m_colours[y*m_width+x].r = colour.r;
  m_colours[y*m_width+x].g = colour.g;
  m_colours[y*m_width+x].b = colour.b;

}

void Image::Export(const char *path) const
{
  std::ofstream f;

  f.open(path, std::ios::out | std::ios::binary);


  if(!f.is_open()){
    std::cout << "File not opened\n";
    return;
  }

  unsigned char bmpPad[3] = {0,0,0};
  const int paddingAmount = ((4-(m_width * 3) % 4) % 4);

  const int fileHeaderSize = 14;
  const int informantionHeaderSize = 40;
  const int fileSize = fileHeaderSize + informantionHeaderSize + m_width * m_height * 3 + paddingAmount * m_height;

  unsigned char fileheader[fileHeaderSize];

  // File type
  fileheader[0] = 'B';
  fileheader[1] = 'M';
  // File size
  fileheader[2] = fileSize;
  fileheader[3] = fileSize >> 8;
  fileheader[4] = fileSize >> 16;
  fileheader[5] = fileSize >> 24;
  // Reserve 1
  fileheader[6] = 0;
  fileheader[7] = 0;
  // Reserve 2
  fileheader[8] = 0;
  fileheader[9] = 0;
  // Pixel Data offset
  fileheader[10] = fileHeaderSize + informantionHeaderSize;
  fileheader[11] = 0;
  fileheader[12] = 0;
  fileheader[13] = 0;
  
  unsigned char informationheader[informantionHeaderSize];

  informationheader[0] = informantionHeaderSize;
  informationheader[1] = 0;
  informationheader[2] = 0;
  informationheader[3] = 0;
  //Image width
  informationheader[4] = m_width;
  informationheader[5] = m_width >> 8;
  informationheader[6] = m_width >> 16;
  informationheader[7] = m_width >> 24;
  // Image height
  informationheader[8] = m_height;
  informationheader[9] = m_height >> 8;
  informationheader[10] = m_height >> 16;
  informationheader[11] = m_height >> 24;
  // Planes
  informationheader[12] = 1;
  informationheader[13] = 0;
  //Bits per pixel
  informationheader[14] = 24;
  informationheader[15] = 0;
  // Compression (none)
  informationheader[16] = 0;
  informationheader[17] = 0;
  informationheader[18] = 0;
  informationheader[19] = 0;
  // Image size (no compression)
  informationheader[20] = 0;
  informationheader[21] = 0;
  informationheader[22] = 0;
  informationheader[23] = 0;
  // X pixel per metre (not specified)
  informationheader[24] = 0;
  informationheader[25] = 0;
  informationheader[26] = 0;
  informationheader[27] = 0;
  // Y pixel per metre (not specified)
  informationheader[28] = 0;
  informationheader[29] = 0;
  informationheader[30] = 0;
  informationheader[31] = 0;
  // Total colours 
  informationheader[32] = 0;
  informationheader[33] = 0;
  informationheader[34] = 0;
  informationheader[35] = 0;
  // Import colours  
  informationheader[36] = 0;
  informationheader[37] = 0;
  informationheader[38] = 0;
  informationheader[39] = 0;

  f.write(reinterpret_cast<char*>(fileheader), fileHeaderSize);
  f.write(reinterpret_cast<char*>(informationheader), informantionHeaderSize);


  for (int y = 0; y < m_height; y++)
  {
    for (int x = 0; x < m_width; x++)
    {
      unsigned char r = static_cast<unsigned char>(get_Colour(x,y).r * 255.0f);
      unsigned char g = static_cast<unsigned char>(get_Colour(x,y).g * 255.0f);
      unsigned char b = static_cast<unsigned char>(get_Colour(x,y).b * 255.0f);

      unsigned char colour[] = {b,g,r};

      f.write(reinterpret_cast<char*>(colour), 3);

    }

    f.write(reinterpret_cast<char*>(bmpPad), paddingAmount);
    
  }
  
  f.close();
  std::cout << "File created\n";
}

Colour::Colour() : r(0), g(0), b(0)
{

}

Colour::Colour(float r, float g, float b) : r(r), g(g), b(b)
{
}

Colour::~Colour()
{
}
