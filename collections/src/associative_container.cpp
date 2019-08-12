#include "associative_container.hpp"

// 
// AssociativeContainer iterator member functions ...
//
template< class KeyType, class ValueType >
void AssociativeContainer<KeyType,ValueType>::Iterator::init( AssociativeContainer<KeyType,ValueType>* itsAssociativeContainer )
{
  associativeContainer = itsAssociativeContainer ;
  currentKey = nullptr ;
  currentValue = nullptr ;
  keys.init( associativeContainer->keys() ) ;
}

template< class KeyType, class ValueType >
void AssociativeContainer<KeyType,ValueType>::Iterator::release( void )
{
  keys.release() ;
}

template< class KeyType, class ValueType >
void AssociativeContainer<KeyType,ValueType>::Iterator::reset( void )
{
  currentKey = nullptr ;
  currentValue = nullptr ;
  keys.reset() ;
  keys.init( associativeContainer->keys() ) ;
}

template< class KeyType, class ValueType >
typename AssociativeContainer<KeyType,ValueType>::Iterator& AssociativeContainer<KeyType,ValueType>::Iterator::begin( void )
{
  currentKey = keys.firstItem() ;
  if ( currentKey != nullptr ) currentValue = &( associativeContainer->itemAtPos( *( currentKey ) ) ) ;
  return *this ;
}

template< class KeyType, class ValueType >
typename AssociativeContainer<KeyType,ValueType>::Iterator& AssociativeContainer<KeyType,ValueType>::Iterator::next( void )
{
  currentKey = keys.nextItem() ;;
  if ( currentKey != nullptr ) currentValue = &( associativeContainer->itemAtPos( *( currentKey ) ) ) ;
  return *this ;
}

template< class KeyType, class ValueType >
typename AssociativeContainer<KeyType,ValueType>::Iterator& AssociativeContainer<KeyType,ValueType>::Iterator::end( void )
{
  currentKey = nullptr ;
  currentValue = nullptr ;
  return *this ;
}

template< class KeyType, class ValueType >
bool AssociativeContainer<KeyType,ValueType>::Iterator::isNull( void )
{
  return currentKey = nullptr ;
} 

template< class KeyType, class ValueType >
KeyType* AssociativeContainer<KeyType,ValueType>::Iterator::key( void )
{
  return currentKey ;
}

template< class KeyType, class ValueType >
ValueType* AssociativeContainer<KeyType,ValueType>::Iterator::value( void )
{
  return ( currentKey ) ? ( &( associativeContainer->itemAtPos( *( currentKey ) ) ) ) : ( ValueType* ) nullptr ;
} 
//
// AssociativeContainer member functions ...
//
template< class KeyType, class ValueType >
void AssociativeContainer<KeyType,ValueType>::init( void )
{
  itsKeys.init() ;
  itsValues.init() ;
  //iterator.init( this ) ;
}

template< class KeyType, class ValueType >
void AssociativeContainer<KeyType,ValueType>::release( void )
{
  itsKeys.release() ;
  itsValues.release() ;
  //iterator.release() ;
}

template< class KeyType, class ValueType >
void AssociativeContainer<KeyType,ValueType>::reset( void )
{
  itsKeys.reset() ;
  itsValues.reset() ;
  //iterator.reset() ;
}

template< class KeyType, class ValueType >
ValueType& AssociativeContainer<KeyType,ValueType>::add( const KeyType& key, const ValueType& value )
{
  long slot = itsKeys.indexOf( key ) ;

  if ( slot == -1 ) {
    itsKeys.add( key ) ;
    itsValues.itemAtPos( itsKeys.indexOf( key ) ) = value ;
    slot = itsKeys.indexOf( key ) ;
  }

  return itsValues.itemAtPos( slot ) ;
}

template< class KeyType, class ValueType >
ValueType& AssociativeContainer<KeyType,ValueType>::itemAtPos( const KeyType& key ) // TODO REVISAR, NO SE COMPRENDE LO QUE HACE
{
  long slot = itsKeys.indexOf( key ) ;

  if ( slot == -1 ) {
    itsKeys.add( key ) ;
    itsValues.itemAtPos( itsKeys.indexOf( key ) ) = ValueType() ;
    slot = itsKeys.indexOf( key ) ;
  }

  return itsValues.itemAtPos( slot ) ;
}

template< class KeyType, class ValueType >
bool AssociativeContainer<KeyType,ValueType>::contain( const KeyType& key )
{
  return ( itsKeys.indexOf( key ) != -1 ) ;
}

template< class KeyType, class ValueType >
ValueType AssociativeContainer<KeyType,ValueType>::valueForKey( const KeyType& key )
{
  long slot = itsKeys.indexOf( key ) ;
  return ( slot != -1 ) ? itsValues.itemAtPos( slot ) : ValueType() ;
}

template< class KeyType, class ValueType >
Collection<KeyType> AssociativeContainer<KeyType,ValueType>::keys( void )
{
  return itsKeys ;
}

template< class KeyType, class ValueType >
size_t AssociativeContainer<KeyType,ValueType>::count( void )
{
  return itsKeys.size() ;
}

template< class KeyType, class ValueType >
KeyType* AssociativeContainer<KeyType,ValueType>::firstItem( void )
{
  return itsKeys.firstItem() ;
}

template< class KeyType, class ValueType >
KeyType* AssociativeContainer<KeyType,ValueType>::nextItem( void )
{
  return itsKeys.nextItem() ;
}