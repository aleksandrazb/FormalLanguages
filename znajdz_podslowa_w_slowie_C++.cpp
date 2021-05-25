#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main(void) {

 std::string word;
 std::cout << "Wpisz slowo:" << std::endl;
 std::getline(std::cin, word); 
 
 
 
 std::set<std::string> subwords;
 for(int i=0; i < word.size(); i++) {

    for(int j=i+1; j < word.size(); j++) {

        subwords.insert(word.substr(i, j));
    }
 }

 std::cout << "Slowa: " << std::endl;
 std::copy(subwords.begin(), subwords.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
 

 return 0;
}
