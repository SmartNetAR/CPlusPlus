#ifndef set_hpp
#define set_hpp

#include <stdio.h>

#ifndef static_collection_hpp
# include "collection.cpp"
#endif

template < class ItemType >
struct Set
{
  Collection<ItemType> rep ;

  void init( void ) ;
  void init( const ItemType values[], size_t nbValues ) ;
  void init( Collection<ItemType>& collection ) ;
  void init( Set<ItemType>& set ) ;

  void release( void ) ;
  void reset( void ) ;

  Set<ItemType>& add( const ItemType& item ) ;
  Set<ItemType>& add( ItemType values[], size_t nbValues ) ;
  Set<ItemType>& add( Collection<ItemType>& collection ) ;
  Set<ItemType>& add( Set<ItemType>& set ) ;

  void intersect( Set<ItemType>& set, Set<ItemType>& result ) ;
  Set<ItemType> intersect( Set<ItemType>& rhs ) ;

  void setUnion( Set<ItemType>& set, Set<ItemType>& result ) ;
  Set<ItemType> setUnion( Set<ItemType>& rhs ) ;

  Set<ItemType> difference( const Set<ItemType>& rhs ) const ;

  Set<ItemType> symetricDifference( const Set<ItemType>& rhs ) const ;

  Collection<ItemType> asCollection( void ) const ;

  size_t size( void ) const ;

  bool isEmpty( void ) const ;

  bool isFull( void ) const ;
  bool subset( const Set<ItemType>& rhs ) const ;

  bool contain( const ItemType& thisItem ) ;

  Set<ItemType> assign( const Set<ItemType>& rhs ) ;

  ItemType* firstItem( void ) ;
  ItemType* nextItem( void ) ;
} ;


#endif