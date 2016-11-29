#include <vector>
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
	for(auto const& c : v) os << c << ' ';
	os << std::endl;
	return os;
}
