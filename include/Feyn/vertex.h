#ifndef VERTEX_H
#define VERTEX_H

#include<vector>

class Vertex
{
public:
  Vertex();
  Vertex(int, int);

  int get_ID();

  std::vector<int> get_pos();
  void set_pos(std::vector<int>);
  void set_pos(int, int);



private:

  inline static int numInstances = 0;
  int ID;
  std::vector<int> pos;

};

#endif // VERTEX_H