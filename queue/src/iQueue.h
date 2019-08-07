#ifndef iQueue_h
#define iQueue_h

typedef int Type ;

class iQueue
{
public:
  virtual Type enqueue( const Type& item ) = 0 ;
  virtual Type dequeue() = 0 ;
  virtual Type peekFront() = 0 ;
  virtual Type peekBack() = 0 ;

};

#endif