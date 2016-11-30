#include <vector>
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
	os << "[ ";
	for(auto const& c : v) os << c << ' ';
	os << "]" << std::endl;
	return os;
	
	// faster ?
	// void print(const std::vector<T>& v){
		// std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
		// std::cout << std::endl;
	// }
}

// Double vector print, follow leetcode convention
// Although Single vector print also work, but less pretty
template <typename T>
std::ostream& operator<<(
	std::ostream& os, 
	const std::vector<std::vector<T> > &vv
	)
{
	os << "[" << std::endl;
	for(auto const& c : vv) os << "  " << c ;
	os << "]" << std::endl;
	return os;
}


