#include <vector>
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
	for(auto const& c : v) os << c << ' ';
	os << std::endl;
	return os;
}



// faster ?
// void print(const std::vector<T>& v){
	// std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
	// std::cout << std::endl;
// }
