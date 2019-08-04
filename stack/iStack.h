#ifndef iStack_h
#define iStack_h

typedef int Type ;

class iStack
{
public:
  virtual void push( const Type& item ) = 0 ;
  virtual Type pop() = 0 ;
  virtual Type peek() = 0 ;

};

#endif