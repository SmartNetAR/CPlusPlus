#include "../ContarPalabras.cpp"

#ifndef collection_cpp
# include "../../../collections/src/collection.cpp"
#endif

// #ifndef set_hpp
// # include "../../collections/src/set.cpp"
// #endif

#include <iostream>

int main(int argc, char const *argv[])
{
  std::cout << "Contar Palabras v2." << std::endl ;
  std::cout << "Escriba una frase y termine con punto(.)." << std::endl ;

  Collection<Word> listOfWords; listOfWords.init() ;
  Collection<int> listOfFrecuencies ; listOfFrecuencies.init() ;
  
  Word word ; word.init() ;

  size_t wordInText = 0 ;
  
  // Mientras haya una palabra en el texto obtenerla y procesarla
  while( !word.assign( getWordFromText() ).isNull() ) {
      process( word ) ;
      // si la palabra no está en la listaDePalabras, la agrega ...
      if ( !listOfWords.contain( word ) ) listOfWords.add( word ) ; 
      // en este punto la palabra está en la lista de palabras
      // solo nos resta incrementar la lista de frecuencias
      listOfFrecuencies.itemAtPos( listOfWords.indexOf( word ) )++ ;

      wordInText++ ;
  }
  // itera sobre la lista de palabras para mostrar la palabra y su frecuencia

  std::cout << "Words in list : " << listOfWords.size() << std::endl ;
  Word* current = listOfWords.firstItem() ;
  while( current ) {
    std::cout << "word: " << current->c_string()
              << " occurs: " << listOfFrecuencies.itemAtPos( listOfWords.indexOf( *current ) )
              << " times" << std::endl ;
    current = listOfWords.nextItem() ;
  }
  listOfFrecuencies.release() ;
  listOfWords.release() ;

  std::cout << std::endl ;
  return 0;
}

