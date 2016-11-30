#include <vector>
#include <iostream>
#include <algorithm>
#include "../myVectorFunc.cpp"
using namespace std;

/* Failed Idea
Since 015_3Sum can only use unique tuple, then the max possible duplicate is two , i.w. [x,x,y]. The only excaption is [0,0,0]

Consider there are 3+ same number in nums, say
	x x x ... x y z
Then according to our algorithm, it will choose 
[x(0) x(1) z] when b = x(1)
[x(0) x(2) z] when b = x(2), considered duplicate
[x(1) x(2) z] when b = x(2), considered duplicate

Therefore, by removing the duplicate number down to 2
	x x y z
the previous duplicated sets will be removed as well.

*/

vector<vector<int>> threeSum(vector<int>& nums) {
	// initialize the output, in case they need return
	vector<vector<int>> vv;
	
	if (nums.size() < 3) return vv;
	
	// sort and remove duplicates to 2
	sort(nums.begin(), nums.end());
	vector<int> nums_maxdup2;
	nums_maxdup2.reserve(nums.size());
	{	
		int count = 0, pre = nums[0];
		nums_maxdup2.push_back(nums[0]);
		
		for (int i = 1; i < nums.size(); i++){
			if (pre == nums[i]) count++;
			else{
				pre = nums[i];
				count = 0;
			}
			if (pre != 0 && count < 2)
				nums_maxdup2.push_back(nums[i]);
			if (pre == 0 && count < 3)
				nums_maxdup2.push_back(nums[i]);
		}
		// cout << "nums_dup: " << nums_maxdup2;
	}
		
	if (nums_maxdup2.size() < 3) return vv;
	
	int idxa = 0, idxc = 0, required_sum = 0;
	int a_plus_c = 0;
	for (int idxb = 1; idxb < nums_maxdup2.size() -1 ; idxb++){
		idxa = idxb -1;
		idxc = idxb +1;
		required_sum = -nums_maxdup2[idxb];
		
		while (idxa >= 0 && idxc < nums_maxdup2.size()){	a_plus_c = nums_maxdup2[idxa] + nums_maxdup2[idxc];			
			if (a_plus_c == required_sum){
				vv.push_back({
					nums_maxdup2[idxa],
					nums_maxdup2[idxb],
					nums_maxdup2[idxc]
				});
				idxa --;
				idxc ++;
			}
			else if (a_plus_c > required_sum)
				idxa --;
			else
				idxc ++;
		}
	}
	
	return vv;
}


// vector<vector<int>> threeSum(vector<int>& nums) {
	// // initialize the output, in case they need return
	// vector<vector<int>> vv;
	// if (nums.size() < 3) return vv;
	
	// // create a map, which contains how many things duplicate
	// sort(nums.begin(), nums.end());
	// {
		
	// }
	
	
	
	// return vv;
// }
int main(){
	// vector<int> v1 {-1, 0, 1, 2, -1, -4,-1}; 
	// vector<int> v1 {};
	// vector<int> v1 {0,0,0};
	vector<int> v1 {-1,0,1,0};
	
	auto vv = threeSum(v1);
	// print the result
	cout << "{" << endl;
	for(auto const& c : vv) cout << c ;
	cout << "}" << endl;
	
	return 0;
}
