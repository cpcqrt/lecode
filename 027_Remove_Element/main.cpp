// Leetcode History
//  - - - - - - 2016/11/30 Beat 62.25%

#include <vector>
#include <iostream>
#include <algorithm>
#include "../myVectorFunc.cpp"
#include "../GeneralFunc.cpp"

using namespace std;
int removeElement(vector<int>& nums, int val) {
	int last_idx = nums.size()-1;
	DEBUG_PRINT(nums);
	DEBUG_PRINT(last_idx);

	// if (last_idx == 0 && nums[0] == val){
		
		
	// }
	
	for (int i = 0; i < nums.size() && i < last_idx; i++){
		if(nums[i] == val){
			std::swap(nums[i], nums[last_idx--]);
			i--; 
			DEBUG_PRINT(nums);
			DEBUG_PRINT(last_idx);
			continue;
		}
	}
	nums.resize(last_idx + 1);
	return last_idx + 1;
}

int main(){
	// vector<int> v1 {3,2,2,3};	int val = 3;
	vector<int> v1 {1};	int val = 1;
	auto new_length = removeElement(v1,val); 
	std:: cout << v1 << std::endl;
	return 0;
}
