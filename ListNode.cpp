#include <vector>
#include <iostream>

// cheat : http://www.learn-c.org/en/Linked_lists
template <typename T>
struct ListNode_Base{
     T val;
     ListNode_Base<T> *next;
     ListNode_Base(T x) : val(x), next(NULL) {}
 };
 
template <typename T>
ListNode_Base<T>* assign_ListNode(const std::vector<T> &v) {
	if(v.size() == 0) return nullptr;

	ListNode_Base<T> *start = new ListNode_Base<T>(v[0]);;
	ListNode_Base<T> *pre   = start;
	
	for (int i = 1; i< v.size(); i++){
		ListNode_Base<T> *ptr = new ListNode_Base<T>(v[i]);
		pre -> next = ptr;
		pre = ptr; // same: pre = pre->next;
	}
	return start;
 }
 
 
template <typename T>
void print_ListNode(const ListNode_Base<T> * head) {
	// use 'type const *head' means a "constant pointer" to type
	// here we use "pointer point to const content"
	const ListNode_Base<T>* current = head; 
	while (current != NULL) {
		std::cout <<  current->val << " ";
		current = current->next;
	}
	std:: cout << std::endl;
}

template<typename T>
void clear_ListNode(ListNode_Base<T> * head){
	while (head != NULL) {
		// print_ListNode(head);
		ListNode_Base<T> *ptr = head;		
		head = head -> next;
		delete (ptr);
	}
}
