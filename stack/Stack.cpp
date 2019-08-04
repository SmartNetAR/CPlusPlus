#ifndef Stack_cpp
#define Stack_cpp

#ifndef iStack_h
# include "iStack.h"
#endif

class Stack :public iStack
{
  enum { DEFAULT_STACK_CAPACITY = 30 } ;

public:
  Stack( unsigned int itsCapacity );
  virtual void push( const Type& item ) ;
  virtual Type pop() ;
  virtual Type peek() ; 
  ~Stack();

private:
  unsigned int stackCapacity ;
  Type _item ;
  int top ;
};

Stack::Stack( unsigned int itsCapacity )
{
  _item = 0 ;
}

void Stack::push( const Type& item ) {
  _item = item ;
}

Type Stack::pop( ) {
  return _item ;
}

Type Stack::peek( ) {
  return _item ;
}

Stack::~Stack()
{
}

#endif