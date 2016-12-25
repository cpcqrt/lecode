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
	for (int i = 0; i < nums.size() && i < last_idx; i++){
		if(nums[i] == val){
			std::swap(nums[i], nums[last_idx--]);
			i--; continue;
		}
	}
	nums.resize(last_idx);
	return last_idx;
}

int main(){
	vector<int> v1 {3,2,2,3};	int val = 3;
	auto new_length = removeElement(v1,val); 
	std:: cout << v1 << std::endl;
	return 0;
}
