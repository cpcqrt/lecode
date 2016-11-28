#include <vector>
#include <iostream>


template <typename T>
struct ListNode {
     T val;
     ListNode<T> *next;
     ListNode(T x) : val(x), next(NULL) {}
 };
 
template <typename T>
const ListNode<T>* assign_ListNode(const std::vector<T> &v) {
	if(v.size() == 0) return nullptr;
	
	// TODO: not done yet
	// ListNode<T> *start;
	// for (int i = 0; i< v.size(); i++){
		// ListNode<T> *ptr = new ListNode<T>(v[i]);
		// if (i == 0) start = ptr;
		
		
	// }
	return start;
 }
 
int main(){
	ListNode<int> *ptr = new ListNode<int>(4);
	std::cout << ptr->val << std::endl;
	return 0;
}
