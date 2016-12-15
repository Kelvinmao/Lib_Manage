#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

bool Comp(int &a, int &b){
	return a > b;
}

int main(void){
	vector<int> nums(10, 0);
	int index = 0;
	for (auto num : nums){
		num = index++;
	}
	sort(nums.begin(),nums.end(), Comp);
	for (auto num : nums){
		cout << num << " ";
	}
	system("pause");
	return 0;
}