#include "text_handlers.h"

std::string to_lower( std::string text ) {
  std::transform( text.begin(), text.end(), text.begin(), []( unsigned char c ){ return std::tolower( c ); } );
  return text;
}

std::string to_no_marks( std::string text ) {
  for ( auto it = text.begin(); it != text.end(); )
    if ( !std::isspace( *it ) && !std::isalpha( *it ) )
      it = text.erase( it );
    else it++;
  return text;
}

std::string to_dotted_word( std::string word ) {
  word.insert( 0, 1, '.' );
  word.push_back( '.' );
  return word;
}

std::vector<std::string> to_words( std::string text ) {
  text.push_back( ' ' );
  std::vector<std::string> words;
  std::string buffer = "";
  for ( auto symbol : text )
    if ( std::isspace( symbol ) ) {
      if ( !buffer.empty() ) {
        words.push_back( buffer );
        buffer.clear();
      }
    } else buffer.push_back( symbol );
  return words;
}

std::vector<std::string> to_ngrams( std::string word, const size_t n ) {
  std::vector<std::string> ngrams;
  const size_t bound = word.size() - n + 1;
  for ( size_t i = 0; i < bound; ++i )
    ngrams.push_back( word.substr( i, n ) );
  return ngrams;
}