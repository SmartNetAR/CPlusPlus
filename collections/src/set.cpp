#include "set.hpp"

template< class ItemType >
void Set<ItemType>::init( void )
{
  rep.init() ;
}

template< class ItemType >
void Set<ItemType>::init( const ItemType values[], size_t nbValues )
{
  rep.init() ;
  for ( int i = 0; i < nbValues; i++ ) {
    if ( isEmpty() ) {
      rep.add( values[ i ] ) ;
    } else {
      if ( !contain( values[i] ) ) rep.add( values[ i ] ) ;
    }
  }
}

template< class ItemType >
void Set<ItemType>::init( Collection<ItemType>& collection )
{
  rep.init() ;
  ItemType* item = collection.firstItem() ;
  while ( item ) {
    if ( collection.isEmpty() ) {
      rep.add( *item ) ;
    } else if ( !contain( *item ) ) {
      rep.add( *item ) ;
    }
    item = collection.nextItem() ;
  }
}

template< class ItemType >
void Set<ItemType>::init( Set<ItemType>& set )
{
  rep.init( set.rep ) ;
}

template< class ItemType >
size_t Set<ItemType>::size( void ) const
{
  return rep.size() ;
}

template< class ItemType >
bool Set<ItemType>::isEmpty( void ) const
{
  return rep.isEmpty() ;
}

template< class ItemType >
bool Set<ItemType>::isFull( void ) const
{
  return rep.isFull() ;
}

template< class ItemType >
bool Set<ItemType>::contain( const ItemType& thisItem )
{
  bool result = false ;
  ItemType* item = rep.firstItem() ;
  while ( item && !result )
  {
    // if ( *item == thisItem )
    if ( memcmp( item, &thisItem, sizeof( ItemType ) ) == 0 ) result = true ;
    item = rep.nextItem() ;
  }
  return result ;
}

template< class ItemType >
Set<ItemType>& Set<ItemType>::add( const ItemType& item )
{
  if ( !contain( item ) ) rep.add( item ) ;
  return *this ;
}

template< class ItemType >
Set<ItemType>& Set<ItemType>::add( ItemType values[], size_t nbValues )
{
  for ( int i = 0; i < nbValues; i++ ) {
    if ( isEmpty() ) {
      rep.add( values[ i ] ) ;
    } else if ( !contain( values[ i ] ) ) {
      rep.add( values[ i ] ) ;
    }
  }
  return *this ;
}

template< class ItemType >
Set<ItemType>& Set<ItemType>::add( Collection<ItemType>& collection )
{
  ItemType* item = collection.firstItem() ;
  while ( item )
  {
    if ( collection.isEmpty() ) {
      rep.add( *item ) ;
    } else if ( !contain( *item ) ) {
      rep.add( *item ) ;
    }
    item = collection.nextItem() ;
  }
  return *this ;  
}

template< class ItemType >
Set<ItemType>& Set<ItemType>::add( Set<ItemType>& set )
{
  ItemType* item = set.firstItem() ; // original rep.firstItem() ;
  while ( item )
  {
    if ( isEmpty() ) {
      add( *item ) ;
    } else if ( !contain( *item ) ) {
      add( *item ) ;
    }
    item = set.nextItem() ; // original nextItem() ;
  }
  return *this ;
}

template< class ItemType >
void Set<ItemType>::intersect( Set<ItemType>& set, Set<ItemType>& result )
{
  ItemType* item = rep.firstItem() ;
  while ( item )
  {
    if ( set.contain( *item ) ) result.add( *item ) ;
    item = rep.nextItem() ;
  }
}

template< class ItemType >
Set<ItemType> Set<ItemType>::intersect( Set<ItemType>& rhs )
{
  Set<ItemType> result ;
  result.init() ;
  intersect( rhs, result ) ;
  return result ;
}

template< class ItemType >
void Set<ItemType>::setUnion( Set<ItemType>& set, Set<ItemType>& result )
{
  result.reset() ;
  result.init( *this ) ;
  ItemType* item = set.firstItem() ;
  while ( item )
  {
    if ( !contain( *item ) ) result.add( *item ) ; // TODO probar, da la union ?
    item = set.nextItem() ;
  }
}

template< class ItemType >
Set<ItemType> Set<ItemType>::setUnion( Set<ItemType>& rhs )
{
  Set<ItemType> result ; result.init() ;
  setUnion( rhs, result ) ;
  return result ;
}

template< class ItemType >
Set<ItemType> Set<ItemType>::difference( const Set<ItemType>& rhs ) const
{
  // The set difference { 1, 2, 3 } \ { 2, 3, 4 } is { 1 }, while
  // conversely, the set difference { 2, 3, 4 } \ { 1, 2, 3 } is { 4 }
  Set<ItemType> result ; result.init() ;
  return result ;
}

template< class ItemType >
Set<ItemType> Set<ItemType>::symetricDifference( const Set<ItemType>& rhs ) const
{
  Set<ItemType> result ; result.init() ;
  return result ;
}

template< class ItemType >
Collection<ItemType> Set<ItemType>::asCollection( void ) const
{
  Collection<ItemType> result ;
  result.init( rep.items ) ;
  return result ;
}

template< class ItemType >
Set<ItemType> Set<ItemType>::assign( const Set<ItemType>& rhs )
{
  rep.asign( rhs.rep ) ;
  return *this ;
}

template< class ItemType >
ItemType* Set<ItemType>::firstItem( void )
{
  return rep.firstItem() ;
}

template< class ItemType >
ItemType* Set<ItemType>::nextItem( void )
{
  return rep.nextItem() ;
}

template< class ItemType >
void Set<ItemType>::release( void )
{
  rep.release() ;
}

template< class ItemType >
void Set<ItemType>::reset( void )
{
  rep.reset() ;
}

template< class ItemType >
bool Set<ItemType>::subset( const Set<ItemType>& rhs ) const
{
  return true ;
}