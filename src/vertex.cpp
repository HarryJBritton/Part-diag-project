#include<Feyn/vertex.h>
#include<iostream>

Vertex::Vertex(){
  
  numInstances += 1;
  ID = numInstances;
  pos = {0, 0};
}

Vertex::Vertex(int positionX, int positionY){

  numInstances += 1;
  ID = numInstances;

  pos = {positionX, positionY};
}


int Vertex::get_ID()
{
  return ID;
}



std::vector<int> Vertex::get_pos()
{
  return pos;
}

void Vertex::set_pos(std::vector<int> position)
{
  pos = position;
}

void Vertex::set_pos(int positionX, int positionY)
{
  pos = {positionX, positionY};
}


