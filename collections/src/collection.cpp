#include "collection.hpp"
/* implementar
static bool allItems( const ItemType& lhs ) ;
static void simple_loyaut( const ItemType& item ) ;
*/  
//
// init family functions
//
template< class ItemType >
void Collection<ItemType>::init( void ) {
  first = 0 ;
  current = nullptr ;
  last = 0 ;
  count = 0 ;

  initialized = true ;
}

template< class ItemType >
void Collection<ItemType>::init( const ItemType values[], size_t nbValues )
{
  #ifdef __DEBUG__
    assert( nbValues <= DEFAULT_CAPACITY ) ;
  #endif // __DEBUG__

  memcpy( items, values, nbValues * sizeof( ItemType ) ) ;

  first = 0 ;
  current = nullptr ;
  last = nbValues - 1 ;

  count = nbValues ;

  initialized = true ;
}

template< class ItemType >
void Collection<ItemType>::init( Collection<ItemType>& otherCollection )
{
  #ifdef __DEBUG__
    assert( otherCollection.initialized ) ;
  #endif // __DEBUG__

  memcpy( items, otherCollection.items, otherCollection.count * sizeof( ItemType ) ) ;

  first = 0 ;
  current = nullptr ;
  last = otherCollection.count -1 ;

  count = otherCollection.count ;

  initialized = true ;
}
//
// release and reset family functions
//
template< class ItemType >
void Collection<ItemType>::release( void )
{
  init() ;
}

template< class ItemType >
void Collection<ItemType>::reset( void )
{
  init() ;
}
//
// add family functions
//
template< class ItemType >
void Collection<ItemType>::add_item( Collection<ItemType>& collection, const ItemType& item )
{
  #ifdef __DEBUG__
    assert( collection.count < DEFAULT_CAPACITY ) ;
  #endif // __DEBUG__

  unsigned long placeForNewItem = collection.count ;
  collection.items[ placeForNewItem ] =  item ;

  if ( collection.count == 0 ) {
    // la coleccion está vacía
    collection.first = 0 ;
    collection.current = nullptr ;
    collection.last = 0 ;
  } else {
    // ya tiene items
    collection.last++ ;
  }
  collection.count++ ;

  #ifdef __DEBUG__
    assert( ( collection.count == placeForNewItem + 1 ) && ( collection.count <= DEFAULT_CAPACITY ) ) ;
    assert( collection.last == collection.first + ( collection.count - 1 ) ) ;
  #endif // __DEBUG__
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::add( const ItemType& item )
{
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__

  add_item( *this, item ) ;

  return *this ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::add( const ItemType values[], size_t nbValues )
{
  #ifdef __DEBUG__
    assert( initialized ) ;
    assert( ( count + nbValues ) <= DEFAULT_CAPACITY ) ;
  #endif // __DEBUG__

  for ( int index = 0; index < nbValues; index++ ) {
    add_item( *this, values[ index ] ) ;
  }

  return *this ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::add( Collection<ItemType>& otherCollection )
{
  #ifdef __DEBUG__
    assert( initialized ) ;
    assert( ( count + otherCollection.count ) <= DEFAULT_CAPACITY ) ;
  #endif // __DEBUG__

  for ( int index = 0; index < otherCollection.count; index++ ) {
    add_item( *this, otherCollection.items[ index ] ) ;
  }

  return *this ;
}
//
// remove family functions
//
template< class ItemType >
Collection<ItemType>& Collection<ItemType>::remove_first( Collection<ItemType>& collection )
{
  if ( collection.count > 1 ) {
    memmove( &( collection.items[0] ), &collection.items[ 1 ], ( collection.count - 1 ) * sizeof( ItemType ) ) ;
    collection.items[ last ] = ( ItemType ) NULL_ITEM ;
    collection.last-- ;
  } else {
    // primero y último ...
    collection.items[ 0 ] = ( ItemType ) NULL_ITEM ;
    collection.first = EMPTY ;
    collection.last = EMPTY ;
  }
  collection.count-- ;

  #ifdef __DEBUG__
    assert( collection.last == collection.first + ( collection.count - 1 ) ) ;
  #endif // __DEBUG__

  return collection ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::remove_last( Collection<ItemType>& collection )
{
  #ifdef __DEBUG__
    assert( collection.initialized ) ;
  #endif // __DEBUG__

  if ( collection.count > 1 ) {
    collection.items[ collection.count - 1 ] = ( ItemType ) NULL_ITEM ;
    collection.last-- ;
  } else {
    collection.items[ 0 ] = ( ItemType ) NULL_ITEM ;
    collection.first = EMPTY ;
    collection.last = EMPTY ;
  }
  collection.count-- ;

  #ifdef __DEBUG__
    assert( collection.last == collection.first + ( collection.count -1 ) ) ;
  #endif // __DEBUG__

  return collection ;

}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::remove_item( Collection<ItemType>& collection, unsigned long pos )
{
  #ifdef __DEBUG__
    assert( collection.initialized ) ;
    assert( ( pos >= 0 ) && ( pos < collection.count ) ) ;
  #endif // __DEBUG__

  if ( pos == 0 ) {
    remove_first( collection ) ;
  } else if ( pos == collection.count - 1 ) {
    remove_last( collection ) ;
  } else {
    // remove other
    memmove( &( collection.items[ pos ] ),
            &( collection.items[ pos + 1 ] ),
            ( ( collection.last - collection.first ) - pos ) * sizeof( ItemType ) 
    ) ;
    collection.last-- ;
    collection.count-- ;
  }

  #ifdef __DEBUG__
    assert( collection.last == collection.first + ( collection.count - 1 ) ) ;
  #endif // __DEBUG__

  return collection ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::removeFirst( void )
{
  #ifdef __DEBUG__
    assert( collection.initialized ) ;
  #endif // __DEBUG__

  if ( count > 0 ) __remove_first__( *this ) ;

  return *this ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::removeLast( void )
{
  #ifdef __DEBUG__
    assert( collection.initialized ) ;
  #endif // __DEBUG__

  if ( count =! 0 ) remove_last( *this ) ;

  return *this ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::remove( const ItemType& item )
{
  #ifdef __DEBUG__
    assert( initializad ) ;
  #endif // __DEBUG__

  unsigned long itemPos = indexOf( item ) ;
  if ( itemPos != -1 ) remove_item( *this, itemPos ) ;

  return *this ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::remove( ItemType values[], size_t nbValues )
{
  #ifdef __DEBUG__
    assert( values != 0 ) ;
  #endif // __DEBUG__

  for ( int index = 0; index < nbValues; index++ ) {
    remove( values[ index ] ) ;
  }

  return *this ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::remove( Collection<ItemType>& itemsToRemove )
{
  #ifdef __DEBUG__
    assert( itemsToRemove.initialized ) ;
  #endif // __DEBUG__

  ItemType* current = itemsToRemove.firstItem() ;
  while ( current )
  {
    remove( *current ) ;
    current = itemsToRemove.nextItem() ;
  }

  return *this ;
  
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::remove( Condition condition )
{
  #ifdef __DEBUG__
    assert( condition != nullptr ) ;
  #endif // __DEBUG__

  ItemType* current = firstItem() ;
  while( current ) {
    if ( condition( *current ) ) remove( *current ) ;
    current = nextItem() ;
  }

  return *this ;
}
//
// query family functions
//
template< class ItemType >
size_t Collection<ItemType>::size( void ) const {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__
  return count ;
}

template< class ItemType >
size_t Collection<ItemType>::capacity( void ) const {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__
  return DEFAULT_CAPACITY ;
}

template< class ItemType >
bool Collection<ItemType>::isEmpty( void ) const {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__
  return first == EMPTY ;
}

template< class ItemType >
bool Collection<ItemType>::isFull( void ) const {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__
  return count == DEFAULT_CAPACITY ;
}

template< class ItemType >
long Collection<ItemType>::indexOf( const ItemType& item ) const {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__

  bool found = false ;
  long pos = - 1 ;

  for( long index = 0; index < count && !found; index ++ ) {
    if ( memcmp( &items[ index ], &item, sizeof( ItemType ) ) == 0  )
    {
      found = true ;
      pos = index ;
    }
  }

  return pos ;
}

template< class ItemType >
ItemType& Collection<ItemType>::itemAtPos( unsigned long pos ) {
  #ifdef __DEBUG__
    assert( ( pos >= 0 ) && ( pos < count ) ) ;
  #endif // __DEBUG__
  return items[ pos ] ;
}

template< class ItemType >
ItemType Collection<ItemType>::itemAtPos( unsigned long pos ) const {
  #ifdef __DEBUG__
    assert( ( pos >= 0 ) && ( pos < count ) ) ;
  #endif // __DEBUG__
  return items[ pos ] ;
}

template< class ItemType >
bool Collection<ItemType>::contain( const ItemType& item ) const {
  return indexOf( item ) != -1 ;
}

template< class ItemType >
Collection<ItemType>& Collection<ItemType>::asign( const Collection<ItemType>& rhs ) const {
  release() ;
  init( rhs ) ;
  return *this ;
}
//
// power loop ( a.k.a iterator ) family functions
//
template< class ItemType >
ItemType* Collection<ItemType>::firstItem( void ) {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__

  ItemType* result = nullptr ;

  if ( count != 0 ) {
    result = &( items[first] ) ;
    current = result ;
  }

  return result ;
}

template< class ItemType >
ItemType* Collection<ItemType>::nextItem( void ) {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__

  ItemType* next = ( ItemType* ) nullptr ;
  ItemType* previus = current ;

  if ( current < ( items + ( count - 1 ) ) )  {
    next = ++current ;
  } else {
    current = previus ;
  }

  return next ;
}
//
// agregate family functions
//
template< class ItemType >
Collection<ItemType> Collection<ItemType>::select( Condition condition ) {
  #ifdef __DEBUG__
    assert( initialized ) ;
  #endif // __DEBUG__

  Collection result ;
  result.init() ;

  #ifdef __DEBUG__
    assert( result.initialized ) ;
  #endif // __DEBUG__

  ItemType* current = firstItem() ;
  while ( current )
  {
    if ( condition( *current ) ) result.add( *current ) ;
    current = nextItem() ;
  }

  return result ;
}
//
// slicing family functions
//
template< class ItemType >
void Collection<ItemType>::slice( Collection<ItemType>& collection, Collection<ItemType>& result, unsigned long starting,
            unsigned long ending, SlicingPredicate predicate )
{
  #ifdef __DEBUG__
    assert( collection.initialized ) ;
    assert( result.initialized ) ;
    assert( ( starting >= 0 ) && ( starting < collection.count -1 ) ) ;
    assert( ( ending >= 0 ) && ( ending < collection.count -1 ) ) ;
  #endif // __DEBUG__

  if ( ending < starting ) {
    unsigned long temp = starting ;
    starting = ending ;
    ending = temp ;
  }
  #ifdef __DEBUG__
    assert( starting <= ending ) ;
  #endif // __DEBUG__

  for ( size_t pos = starting; pos < count; pos++ ) { // TODO review count ( ending )
    if ( predicate( pos, starting, ending ) ) result.add( items[ pos ] ) ;
  }
}

template< class ItemType >
bool Collection<ItemType>::outerOuterPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending )
{
  return ( itemPos >= starting ) && ( itemPos <= ending ) ; 
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::outerSlice( unsigned long starting, unsigned long ending )
{
  Collection result ;
  result.init() ;
  slice( *this, result, starting, ending, outerOuterPredicate ) ;
  return result ;
}

template< class ItemType >
bool Collection<ItemType>::innerInnerPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending )
{
  return ( itemPos > starting ) && ( itemPos < ending ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::innerSlice( unsigned long starting, unsigned long ending )
{
  Collection result ;
  result.init() ;
  slice( *this, result, starting, ending, innerInnerPredicate ) ;
  return result ;
}

template< class ItemType >
bool Collection<ItemType>::innerOuterPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending )
{
  return ( itemPos > starting ) && ( itemPos <= ending ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::innerOuterSlice( unsigned long starting, unsigned long ending )
{
  Collection result ;
  result.init() ;
  slice( *this, result, starting, ending, innerOuterPredicate ) ;
  return result ;
}

template< class ItemType >
bool Collection<ItemType>::outerInnerPredicate( unsigned long itemPos, unsigned long starting, unsigned long ending )
{
  return ( itemPos >= starting ) && ( itemPos < ending ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::outerInnerSlice( unsigned long starting, unsigned long ending )
{
  Collection result ;
  result.init() ;
  slice( *this, result, starting, ending, outerInnerPredicate ) ;
  return result ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::outerTrimLeft( unsigned long starting ) 
{
  return outerSlice( starting, count -1 ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::innerTrimLeft( unsigned long starting )
{
  return innerSlice( starting, count - 1 ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::innerOuterTrimLeft( unsigned long starting )
{
  return innerOuterSlice( starting, count - 1 ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::outerInnerTrimLeft( unsigned long starting )
{
  return outerInnerSlice( starting, count - 1 ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::outerTrimRight( unsigned long starting )
{
  return outerSlice( 0, starting ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::innerTrimRight( unsigned long starting )
{
  return innerSlice( 0, starting ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::innerOuterTrimRight( unsigned long starting )
{
  return innerOuterSlice( 0, starting ) ;
}

template< class ItemType >
Collection<ItemType> Collection<ItemType>::outerInnerTrimRight( unsigned long starting )
{
  return outerInnerSlice( 0, starting ) ;
}

template< class ItemType >
void Collection<ItemType>::dump( LayoutFunction itemLayout )
{
  for ( int idx = 0; idx < count; idx++ ) itemLayout( items[ idx ] ) ;
}
