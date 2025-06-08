#ifndef VERTEX_H
#define VERTEX_H

#include<vector>

class Vertex
{
public:
  Vertex();
  Vertex(float, float);

  int get_ID();

  std::vector<float> get_pos();
  void set_pos(std::vector<float>);
  void set_pos(float, float);



private:

  inline static int numInstances = 0;
  int ID;
  std::vector<float> pos;

};

#endif // VERTEX_H