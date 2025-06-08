#include<Feyn/vertex.h>
#include<iostream>

Vertex::Vertex(){
  
  ID = numInstances;
  numInstances += 1;
  pos = {0, 0};
}

Vertex::Vertex(float positionX, float positionY){

  ID = numInstances;
  numInstances += 1;
  pos = {positionX, positionY};
}


int Vertex::get_ID()
{
  return ID;
}



std::vector<float> Vertex::get_pos()
{
  return pos;
}

void Vertex::set_pos(std::vector<float> position)
{
  pos = position;
}

void Vertex::set_pos(float positionX, float positionY)
{
  pos = {positionX, positionY};
}


