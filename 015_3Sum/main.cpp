// Leetcode History
// 2016/11/30 Beat 62.25%

#include <vector>
#include <iostream>
#include <algorithm>
#include "../myVectorFunc.cpp"
#include "../GeneralFunc.cpp"

using namespace std;



/* 
There are only 4 cases
* [a,b,c]
* [a,b,b]
* [b,b,c]
* [b,b,b] <-- only [0,0,0]

# [a,b,b] & [a,b,c] 
After finished [a,b,b]. Simply go to [a,b,c] case, and make sure every 
step to a or to c are different values.

Then simply step-b. either go to another same value (to next case) or go to 
different value.

# [b,b,b] & [b,b,c] 
After finished [b,b,b]. Simply go to [b,b,c] case, and make sure every step 
to c is different value. 
Then goto different value b.

*/

vector<vector<int>> threeSum(vector<int>& nums) {
	// initialize the output, in case they need return
	vector<vector<int>> vv;
	
	if (nums.size() < 3) return vv;
	
	sort(nums.begin(), nums.end());
	// create a vector which holds how many time does this 
	// number index. 
	// e.g. 1 1 2 2 2 2 3 3 3 3
	//      0 1 0 1 2 3 0 1 2 3
	vector<int> reps;
	{
		reps.resize(nums.size(), 0); // initial default is 0
		for(int i = 1; i < nums.size(); i++){
			if (nums[i] == nums[i-1]){
				reps[i] = reps[i-1] + 1;
			}			
		}
	}
	DEBUG_PRINT(nums);
	DEBUG_PRINT(reps);
	
	
	int idxa = 0, idxb = 1, idxc = 0;
	
	int required_sum = 0;

	while(idxb < nums.size() -1){
		DEBUG_PRINT(nums[idxb]);
		if (reps[idxb] == 0){		// [a, b, b|c] case
			if (reps[idxb+1] == 1){
				// check [a,b,b] case
				DEBUG_PRINT("[a,b,b] case");
				
				required_sum = -2 * nums[idxb];
				idxa = idxb;
				do {
					idxa --;
					// step to next different a value
					while(idxa > 0 && reps[idxa] > 0) idxa -- ;
					if (idxa < 0) break;
					
					if (nums[idxa] == required_sum)
						vv.push_back({
							nums[idxa],
							nums[idxb],
							nums[idxb]
						});
				} while(nums[idxa] >= required_sum);
			}
			{
				// only need to check [a,b,c] case
				DEBUG_PRINT("[a,b,c] case");
				
				idxa = idxb -1;
				idxc = idxb +1;

				// step to next different a value
				while(idxa > 0 && reps[idxa] > 0) idxa -- ;
				
				// step to next different c value
				while(idxc < nums.size() && reps[idxc] > 0) idxc ++ ;
				
				required_sum = - nums[idxb];
				
				
				while(idxa >= 0 && idxc < nums.size()){
					if (nums[idxa] + nums[idxc] == required_sum){
						vv.push_back({
							nums[idxa],
							nums[idxb],
							nums[idxc]
						});
						
						// step to next different a value
						idxa --;
						while(idxa > 0 && reps[idxa] > 0) idxa -- ;
						
						// step to next different c value
						idxc ++;
						while(idxc < nums.size() && reps[idxc] > 0) idxc ++ ;
					}
					else if ( nums[idxa] + nums[idxc] > required_sum){
						// step to next different a value
						idxa --;
						while(idxa > 0 && reps[idxa] > 0) idxa -- ;
					}
					else {
						// step to next different c value
						idxc ++;
						while(idxc < nums.size() && reps[idxc] > 0) idxc ++ ;
					}
				}
			}
			
			idxb ++; 
		} else if (reps[idxb] == 1) { 
			// [b, b, b|c] case
			// only need to check [b,b, ...]
			// this will also contain [b,b,b] as well
			// [a,b, ...] is already checked when rep[idxb] == 0
			
			if (reps[idxb + 1] == 2 && nums[idxb] == 0){ 
				// check [b,b,b] case
				DEBUG_PRINT("[b,b,b] case");
				vv.push_back({0,0,0});
			} 
			else {
				// check [b,b,c] case
				DEBUG_PRINT("[b,b,c] case");
				
				required_sum = - 2 * nums[idxb];
				
				idxc = idxb;
				
				do{
					idxc ++ ;
					// step to next different c value
					while(idxc < nums.size() && reps[idxc] > 0) idxc ++ ;
					if (idxc >= nums.size()) break;
					
					if (nums[idxc] == required_sum)
						vv.push_back({
							nums[idxb],
							nums[idxb],
							nums[idxc]
						});
					
				} while(nums[idxc] <= required_sum);
			}
			
			// step to next different b value
			idxb ++ ;
			while(idxb < nums.size() && reps[idxb] > 0) idxb ++;
		}
	}
	return vv;
}


int main(){
	// vector<int> v1 {-1, 0, 1, 2, -1, -4,-1}; 
	// vector<int> v1 {};
	// vector<int> v1 {0,0,0};
	// vector<int> v1 {-1,0,1,0};
	// vector<int> v1 {1,1,-2};
	vector<int> v1 {6,9,-8,8,-1,2,-3,-1,9,-8,3,3,9,-10};
	
	auto vv = threeSum(v1);
	// print the result
	
	DEBUG_PRINT(vv);
	
	return 0;
}
