#ifndef collection_hpp
#define collection_hpp

#include <stdio.h>
#include <string>
#include <iostream>

//#define __DEBUG__

template< typename ItemType >
struct Collection
{
  enum { NULL_ITEM = 0, EMPTY = -1, DEFAULT_CAPACITY = 512 } ;

  typedef bool( *Condition ) ( const ItemType& item ) ;
  typedef void( *LayoutFunction ) ( const ItemType& item ) ;
  typedef bool( *SlicingPredicate ) ( unsigned long itemPos, unsigned long starting, unsigned long ending ) ;

  ItemType items[ DEFAULT_CAPACITY ] ;

  size_t first ;
  size_t last ;
  ItemType* current ;

  unsigned long count ;

  bool initialized ;
  //
  // private helper functions
  //
  static bool allItems( const ItemType& lhs ) ;
  static void simple_loyaut( const ItemType& item ) ;
  void add_item( Collection<ItemType>& collection, const ItemType& item ) ;
  Collection<ItemType>& remove_first( Collection<ItemType>& collection ) ;
  Collection<ItemType>& remove_last( Collection<ItemType>& collection ) ;
  Collection<ItemType>& remove_item( Collection<ItemType>& collection, unsigned long pos ) ;
  //
  // slicing family functions
  //
  void slice( Collection<ItemType>& collection, Collection<ItemType>& result, unsigned long starting,
              unsigned long ending, SlicingPredicate predicate ) ;
  static bool outerOuterPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending ) ;
  static bool innerInnerPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending ) ;
  static bool innerOuterPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending ) ;
  static bool outerInnerPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending ) ;
  //
  // init family functions
  //
  void init( void ) ;
  void init( const ItemType& item, size_t count ) ;
  void init( const ItemType values[], size_t nbValues ) ;
  void init( Collection<ItemType>& otherCollection ) ;
  //
  // release and reset family functions
  //
  void release( void ) ;
  void reset( void ) ;
  //
  // add family functions
  //
  Collection<ItemType>& add( const ItemType& item ) ;
  Collection<ItemType>& add( const ItemType values[], size_t nbValues ) ;
  Collection<ItemType>& add( Collection<ItemType>& otherCollection ) ;
  //
  // remove family functions
  //
  Collection<ItemType>& removeFirst( void ) ;
  Collection<ItemType>& removeLast( void ) ;
  Collection<ItemType>& remove( const ItemType& item ) ;
  Collection<ItemType>& remove( ItemType values[], size_t nbValues ) ;
  Collection<ItemType>& remove( Collection<ItemType>& itemsRemove ) ;
  Collection<ItemType>& remove( Condition condition ) ;
  //
  // query family functions
  //
  size_t size( void ) const ;
  size_t capacity( void ) const ;
  bool isEmpty( void ) const ;
  bool isFull( void ) const ;
  long indexOf( const ItemType& item ) const ;
  ItemType& itemAtPos( unsigned long pos ) ;
  ItemType itemAtPos( unsigned long pos ) const ;
  bool contain( const ItemType& item ) const ;
  Collection<ItemType>& asign( const Collection<ItemType>& rhs ) const ;
  //
  // power loop ( a.k.a iterator ) family functions
  //
  ItemType* firstItem( void ) ;
  ItemType* nextItem( void ) ;
  //
  // agregate family functions
  //
  Collection<ItemType> select( Condition condition ) ;

  Collection<ItemType> outerSlice( unsigned long starting, unsigned long ending ) ;
  Collection<ItemType> innerSlice( unsigned long starting, unsigned long ending ) ;
  Collection<ItemType> innerOuterSlice( unsigned long starting, unsigned long ending ) ;
  Collection<ItemType> outerInnerSlice( unsigned long starting, unsigned long ending ) ;

  Collection<ItemType> outerTrimLeft( unsigned long starting ) ;
  Collection<ItemType> innerTrimLeft( unsigned long starting ) ;
  Collection<ItemType> innerOuterTrimLeft( unsigned long starting ) ;
  Collection<ItemType> outerInnerTrimLeft( unsigned long starting ) ;
  Collection<ItemType> outerTrimRight( unsigned long starting ) ;
  Collection<ItemType> innerTrimRight( unsigned long starting ) ;
  Collection<ItemType> innerOuterTrimRight( unsigned long starting ) ;
  Collection<ItemType> outerInnerTrimRight( unsigned long starting ) ;

  void dump( LayoutFunction itemLayout ) ;
} ;

#endif