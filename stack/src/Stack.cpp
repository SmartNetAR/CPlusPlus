#ifndef Stack_cpp
#define Stack_cpp

#ifndef iStack_h
# include "iStack.h"
#endif

enum { DEFAULT_STACK_CAPACITY = 30 } ;

class Stack :public iStack
{
public:
  Stack( unsigned int itsCapacity ) ;
  virtual void push( const Type& item ) ;
  virtual Type pop() ;
  virtual Type peek() ; 
  ~Stack();

private:
  unsigned int stackCapacity ;
  Type* rep ;
  int top ;
  unsigned int count ;
};

Stack::Stack( unsigned int itsCapacity )
  :rep( nullptr ), stackCapacity( itsCapacity ),  count( 0 ), top( -1 )
{
  rep = new Type[ stackCapacity ] ;
}

Stack::~Stack()
{
  if( rep ) delete [] rep ;
}

void Stack::push( const Type& item ) {
  rep[ ++top ] = item ;
  count++ ;
}

Type Stack::pop( ) {
  count-- ;
  return rep[ top-- ] ;
}

Type Stack::peek( ) {
  return rep[ top ] ;
}

#endif