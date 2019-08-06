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
  unsigned int size ;
  int front ;
  int rear ;
  unsigned int count ;
  bool isEmpty() ;
};

Queue::Queue( unsigned int itsCapacity )
  :rep( nullptr ), size( itsCapacity ), front( -1 ), rear( -1 ), count( 0 )
{
  rep = new Type[ size ] ;
}

Queue::~Queue()
{
  if( rep ) delete [] rep ;
}

Type Queue::enqueue( const Type& item ) {
  if ( rear == -1) {
    front = 0 ;
    rear = 0 ;
  } else {
    rear++ ;
  }
  count++ ;
  return rep[ rear ] = item ;
}

Type Queue::dequeue() {
  if ( !isEmpty() ) {
    count-- ;
    return rep[ front++ ] ;
  }
}

Type Queue::peek() {
  if ( !isEmpty() ) {
    return rep[ front ] ;
  }
}

bool Queue::isEmpty() {
  return count == 0 ;
}
#endif