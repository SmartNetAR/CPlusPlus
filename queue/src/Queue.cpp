#ifndef Queue_cpp
#define Queue_cpp

#ifndef iQueue_h
# include "iQueue.h"
#endif

enum { DEFAULT_QUEUE_CAPACITY = 30 } ;

class Queue :public iQueue
{
public:
  Queue( unsigned int itsCapacity ) ;
  virtual Type enqueue( const Type& item ) ;
  virtual Type dequeue() ;
  virtual Type peek() ; 
  ~Queue();

private:
  Type* rep ;
  unsigned int queueCapacity ;
  int top ;
  unsigned int count ;
};

Queue::Queue( unsigned int itsCapacity )
  :rep( nullptr ), queueCapacity( itsCapacity ), top( -1 ), count( 0 )
{
  rep = new Type[ queueCapacity ] ;
}

Queue::~Queue()
{
  if( rep ) delete [] rep ;
}

Type Queue::enqueue( const Type& item ) {
  rep[ ++top ] = item ;
  count++ ;
  return rep[ top ] ;
}

Type Queue::dequeue( ) {
  count-- ;
  return rep[ top-- ] ;
}

Type Queue::peek( ) {
  return rep[ top ] ;
}

#endif