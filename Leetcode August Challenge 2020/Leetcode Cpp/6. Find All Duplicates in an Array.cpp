class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
        	int index = abs(nums[i])-1;
        	if(nums[index] < 0) ans.push_back(abs(nums[i]));
        	nums[index] = -nums[index];
		}
        return ans;
    }
};
/*
Method - 2
[4,3,2,7,8,2,3,1]
n = 8
i = 0:
	index = 4
	arr[4] = 8+8 = 16
i = 1:
	index = 3
	arr[3] = 7+8 = 15
i = 2:
	index = 2
	arr[2] = 2+8 = 10
i = 3:
	index = 7
	arr[7] = 1+8 = 9
i = 4:
	index = 0
	arr[0] = 4+8 = 12
i = 5:
	index = 2
	arr[2] = 10+8 = 18
i = 6:
	index = 3
	arr[3] = 15+8 = 23
i = 7:
	index = 1
	arr[1] = 3+8 = 11
[12,11,18,23,16,2,3,9]
void printRepeating( int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
	{ 
		int index = arr[i] % n; 
		arr[index] += n; 
	} 
	for (int i = 0; i < n; i++) 
	{ 
		if ((arr[i]/n) > 2) 
			cout << i << " "; 
	} 
} 
*/
