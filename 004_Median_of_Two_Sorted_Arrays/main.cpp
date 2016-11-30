#include <vector>
#include <iostream>
#include <algorithm>
#include "../myVectorFunc.cpp"

using namespace std;

// TODO: Peek the std version, http://en.cppreference.com/w/cpp/algorithm/merge



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size() + nums2.size();
	// numbers need to be store:
	// n even: n/2-1, n/2
	// n odd :        n/2
	// at least we need to count to n/2
	int idx3_half_1 = n/2 - 1, idx3_half = n/2;
	int val[2] = {0,0};
	
	// start counting, using merge sort technique
	int idx1 = 0, idx2 = 0, idx3 = 0;
	for (;idx1 < nums1.size();idx3++){
		// if (idx2 == num2s.size()){
			// // vector 2 reached end
			// if (idx3 == idx3_half - 1) val[0] = nums1[idx1];
			// if (idx3 == idx3_half)     val[1] = nums1[idx1];
		// }
		// if (nums1[idx1] <= nums2[idx2]){
			// if (idx3 == idx3_half_1) val[0] = nums1[idx1];
			// if (idx3 == idx3_half)   val[1] = nums1[idx1];
			// idx1 ++;
		// } else {			
			// if (idx3 == idx3_half_1) val[0] = nums2[idx2];
			// if (idx3 == idx3_half)   val[1] = nums2[idx2];
			// idx2 ++;
		// }
	}
	
	while ( && idx2 < nums2.size()){
		// filling idx3, while comparing idx1 and idx2
		
		if (idx3 == idx3_half + 1) break;
	}
	// previous loop will end in two condition
	// 1. already filled to idx3_half
	// 2. either vector reached the end
	if (idx3 < idx3_half + 1){
		// either vector reached the end
		if (idx1 == nums1.size()){
			val[0] = nums2[idx3_half - idx2 - 1];
			val[1] = nums2[idx3_half - idx2];
		}
		else if(idx2 == nums2.size()){
			val[0] = nums1[idx3_half - idx1 - 1];
			val[1] = nums1[idx3_half - idx1];
		}
		else{
			throw "Not gonna happen";
		}
		idx3 = idx3_half + 1; // just in case
	}
	if (n % 2 == 0){
		return (double(val[0]) + double(val[1]))/2.0;
	} else {
		return double(val[1]);
	}
}
int main(){
	// vector<int> v1 {2,4,3,9}; 
	// vector<int> v2 {5,6,7,3,11}; 
	vector<int> v1 {1,2}; 
	vector<int> v2 {3,4}; 
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	cout << v1;
	cout << v2;
	
	// Real solution
	std::vector<int> v3;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));	
	cout << v3;
	double median = double(v3[v3.size()/2]);
	if (v3.size()%2 == 0) median = (median + double(v3[v3.size()/2-1]))/2.0;
	cout << "Exact median = " << median << endl;
	
	cout << "  My  median = "
	     << findMedianSortedArrays(v1,v2) << endl;
	return 0;
}
