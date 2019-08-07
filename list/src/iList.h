#ifndef iList_h
#define iList_h

typedef int Type ;

class iList
{
public:
  virtual Type append( const Type& item ) = 0 ;
  virtual Type pop() = 0 ;
  virtual Type peekFront() = 0 ;
  virtual Type peekBack() = 0 ;

};

#endif