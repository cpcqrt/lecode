# include "../ListNode.cpp"
# include "../GeneralFunc.cpp"
# include <vector>

typedef ListNode_Base<int> ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	// make sure l1 and l2 has value, i.e. result must hold something
	if (l1 == NULL && l2 == NULL){
		return NULL;
	}
	int carry = 0, v1 = 0, v2 = 0, val = 0;
	std::vector<int> vec;
	
	// ListNode *start = new ListNode(val);
	ListNode *ptr1 = l1, *ptr2 = l2;
	
	do{
		using namespace std;
		v1 = (ptr1 != NULL)? ptr1 -> val : 0;
		v2 = (ptr2 != NULL)? ptr2 -> val : 0;
		val   = (v1 + v2 + carry )%10;
		carry = (v1 + v2 + carry >= 10)? 1:0;
		
		vec.push_back(val);
		
		ptr1 = (ptr1 == NULL)?NULL : ptr1 -> next;
		ptr2 = (ptr2 == NULL)?NULL : ptr2 -> next;
		
		// debug info
		// cout << "val = " << val << ", carry = " << carry << endl;
		// for (auto const& c : vec)	std::cout << c << ' ';
		// std::cout << std::endl;
		
	} while (ptr1 != NULL || ptr2!= NULL);
	
	if (carry == 1) {
		vec.push_back(carry);
	}
	return assign_ListNode(vec);
}
int main(){
	std::vector<int> v1 {2,4,3,9};
	std::vector<int> v2 {5,6,4,3};
    auto l1 = assign_ListNode(v1); // DEBUG_PRINT(l1);
	auto l2 = assign_ListNode(v2); // DEBUG_PRINT(l2);
	auto l3 = addTwoNumbers(l1,l2); DEBUG_PRINT(l3);
	
	return 0;
}
