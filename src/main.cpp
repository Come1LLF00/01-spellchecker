#include <iostream>

/* USER CODE BEGIN Includes */
#include "main.h"
#include "store.h"
#include "text_handlers.h"
/* USER CODE END Includes */

void test();

int main( int argc, char** argv ) {
  test();
  return 0;
}

void print_store_state( Store & store ) {
  std::cout << "Store[ n: [ " << ( int ) store.get_limit_n() << "; " << store.is_limit_n_used() << " ]; " << "out: [ " << ( int ) store.get_limit_out() << "; " << store.is_limit_out_used() << " ] ]" << std::endl;
}

void test() {
  std::cout << "==== test store ====" << std::endl;

  Store st;
  print_store_state( st );
  st.set_limit_n( 20 );
  print_store_state( st );
  st.set_limit_out( 40 );
  print_store_state( st );

  std::cout << "==== test text handlers ====" << std::endl;

  std::string text;
  std::getline( std::cin, text );

  text = to_lower( text );

  std::cout << "lowered: " << text << std::endl;

  text = to_no_marks( text );

  std::cout << "no marks: " << text << std::endl;

  std::vector<std::string> words = to_words( text );

  for ( auto & word : words ) {
    std::cout << "just word: " << word;
    word = to_dotted_word( word );
    std::cout << "; dotted: " << word << std::endl;

    std::vector<std::string> digrams = to_ngrams( word, 2 );
    for ( auto digram : digrams )
      std::cout << "+ " << digram << std::endl;
    std::cout << "===" << std::endl;
    std::vector<std::string> trigrams = to_ngrams( word, 3 );
    for ( auto trigram : trigrams )
      std::cout << "++ " << trigram << std::endl;
  }
}