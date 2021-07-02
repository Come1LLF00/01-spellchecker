#ifndef _TEXT_HANDLERS_H_
#define _TEXT_HANDLERS_H_

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>


std::string to_lower( std::string text );

std::string to_no_marks( std::string text );

std::string to_dotted_word( std::string word );

std::vector<std::string> to_words( std::string text );

std::vector<std::string> to_ngrams( std::string word, const size_t n );

#endif /* _TEXT_HANDLERS_H_ */