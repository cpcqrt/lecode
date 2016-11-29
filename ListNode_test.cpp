#include "ListNode.cpp"
int main(){
	/* // test constructor
	ListNode_Base<int> *ptr = new ListNode<int>(4);
	std::cout << ptr->val << std::endl;
	*/
	// test assign, print, clear
	std::vector<int> v {1,2,3,5};
	auto l = assign_ListNode(v);
	print_ListNode(l);
	clear_ListNode(l);
	
	return 0;
}
