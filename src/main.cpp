#include <iostream>

/* USER CODE BEGIN Includes */
#include "main.h"
#include "store.h"
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
  std::cout << "Hello, World!" << std::endl;
  Store st;
  print_store_state( st );
  st.set_limit_n( 20 );
  print_store_state( st );
  st.set_limit_out( 40 );
  print_store_state( st );
}