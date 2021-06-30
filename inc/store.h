#ifndef _STORE_H_
#define _STORE_H_

/* USER CODE BEGIN Includes */
#include <cstdint>
#include <string>
#include <unordered_map>
#include <fstream>
/* USER CODE END Includes */

class Store {
private:
  std::uint8_t limit_n;
  std::uint8_t limit_out;
  bool use_limit_n;
  bool use_limit_out;

  char const * const buffer_text = "text.txt"; // full immutable file name

  std::unordered_map<std::string, std::uint64_t> digrams;
  std::unordered_map<std::string, std::uint64_t> trigrams;
public:
  Store();
// getters/setters
public:
  std::uint8_t get_limit_n  ();
  std::uint8_t get_limit_out();

  bool is_limit_n_used  ();
  bool is_limit_out_used();

  void set_limit_n  ( const std::uint8_t n   );
  void set_limit_out( const std::uint8_t out );

  void append_text( const std::string & toappend );
  void clear_text ();
};

#endif /* _STORE_H_ */