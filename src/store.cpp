#include "store.h"
// definitions

Store::Store() : limit_n( 0 ),
  limit_out( 0 ),
  use_limit_n( false ),
  use_limit_out( false ) { }

std::uint8_t Store::get_limit_n  () {
  return limit_n;
}

std::uint8_t Store::get_limit_out() {
  return limit_out;
}

bool Store::is_limit_n_used  () {
  return use_limit_n;
}

bool Store::is_limit_out_used() {
  return use_limit_out;
}

void Store::set_limit_n  ( const std::uint8_t n   ) {
  limit_n       = n;
  use_limit_n   = true;
  use_limit_out = false;
}

void Store::set_limit_out( const std::uint8_t out ) {
  limit_out     = out;
  use_limit_n   = false;
  use_limit_out = true;
}

void Store::append_text( const std::string & toappend ) {
  std::fstream txt;
  txt.open( buffer_text, std::ios_base::app);
  txt << toappend;
  txt.close();
}

void Store::clear_text () {
  std::fstream txt;
  txt.open( buffer_text, std::ios::out | std::ios::trunc );
  txt.close();
}