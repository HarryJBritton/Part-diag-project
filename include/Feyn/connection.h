#ifndef CONNECTION_H
#define CONNECTION_H

class Connection{
public:
  Connection();
  Connection(int, int, int);

  int get_startID();
  void set_startID(int);

  int get_endID();
  void set_endID(int);

  int get_type();
  void set_type(int);

private:
  int startID;
  int endID;
  int type;

};

#endif