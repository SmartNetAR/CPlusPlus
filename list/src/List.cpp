#ifndef List_cpp
#define List_cpp

#ifndef iList_h
# include "iList.h"
#endif

enum { DEFAULT_LIST_CAPACITY = 30 } ;

class List :public iList
{
public:
  List( unsigned int itsCapacity ) ;
  virtual Type append( const Type& item ) ;
  virtual Type pop() ;
  virtual Type peekFront() ; 
  virtual Type peekBack() ; 
  ~List();

private:
  Type* rep ;
  unsigned int size ;
  int front ;
  int rear ;
  unsigned int count ;
  bool isEmpty() ;
};

List::List( unsigned int itsCapacity )
  :rep( nullptr ), size( itsCapacity ), front( -1 ), rear( -1 ), count( 0 )
{
  rep = new Type[ size ] ;
}

List::~List()
{
  if( rep ) delete [] rep ;
}

Type List::append( const Type& item ) {
  if ( rear == -1) {
    front = 0 ;
    rear = 0 ;
  } else {
    rear++ ;
  }
  count++ ;
  return rep[ rear ] = item ;
}

Type List::pop() {
  if ( !isEmpty() ) {
    count-- ;
    return rep[ front++ ] ;
  }
}

Type List::peekFront() {
  if ( !isEmpty() ) {
    return rep[ front ] ;
  }
}

Type List::peekBack() {
  if ( !isEmpty() ) {
    return rep[ rear ] ;
  }
}

bool List::isEmpty() {
  return count == 0 ;
}
#endif