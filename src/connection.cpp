#include<Feyn/connection.h>
#include<iostream>

Connection::Connection(){
  startID = 0;
  endID = 0;
}

Connection::Connection(int start, int end, int connectionType)
{
  if(start < 1){
    std::cout<<"ERR: start vertex ID is invalid\n";
    startID = 0; 
  }else if (end < 1)
  {
    std::cout<<"ERR: end vertex ID is invalid\n";
    endID = 0; 
  }else if (start == end)
  {
    std::cout<<"ERR: start and end vertex ID are the same\n";
    startID = 0; 
    endID = 0; 

  }else
  {
    startID = start; 
    endID = end; 
  }

  if(connectionType < 0)
  {
    std::cout<<"ERR: connection type is invalid\n";
    type = 0;
  }else{
    type = connectionType;
  }
  
  
  
}

int Connection::get_startID()
{
  return startID;
}
void Connection::set_startID(int start)
{
    if(start < 1){
    std::cout<<"ERR: start vertex ID is invalid\n";
    startID = 0; 
  }else if (start == endID)
  {
    std::cout<<"ERR: start and end vertex ID are the same\n";
    startID = 0; 
    endID = 0; 

  }else
  {
    startID = start; 
  }
}

int Connection::get_endID(){
  return endID;
}

void Connection::set_endID(int end){
  if(end < 1){
    std::cout<<"ERR: end vertex ID is invalid\n";
    endID = 0; 
  }else if (startID == end)
  {
    std::cout<<"ERR: start and end vertex ID are the same\n";
    startID = 0; 
    endID = 0; 

  }else 
  {
    endID = end; 
  }
}

int Connection::get_type(){
  return type;
}

void Connection::set_type(int connectionType){
  if(connectionType < 0)
  {
    std::cout<<"ERR: connection type is invalid\n";
    type = 0;
  }else{
    type = connectionType;
  }
}