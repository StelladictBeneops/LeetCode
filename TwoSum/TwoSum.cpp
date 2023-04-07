//The typical approach is to use nested loops where the outer loop iterates 
//through each number in the array, and the inner loop iterates through the 
//remaining numbers to find the complement that adds up to the target. 
//Instead we can use a hash table. Basically, you store each number in the 
//array with its index in the hash table. Then, you loop through the array and 
//calculate the complement of each number. If the complement is already in the 
//hash table, it means you've found the two numbers that add up to the target. 
//You add their indices to the result vector. If the complement isn't in the 
//hash table, you add the current number and its index to the hash table.
//That's way faster than the nested loops approach. The tradeoff is that it 
//requires additional space to store the hash table, but because the hash table 
//contains one entry for each element in the array it runs way faster.


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Create a map to store each number in the array along with its index.
    unordered_map<int, int> map;
    // Create a vector to store the result.
    vector<int> result;

    // Iterate through each number in the array.
    for (int i = 0; i < nums.size(); i++) {
        // Calculate the complement of the current number.
        int complement = target - nums[i];
        
        // Check if the complement is already in the map.
        if (map.count(complement)) {
            // If it is, add the indices of the two numbers to the result vector.
            result.push_back(map[complement]);
            result.push_back(i);
            break;
        }
        
        // If the complement is not in the map, add the current number and its index to the map.
        map[nums[i]] = i;
    }

    // Return the result vector.
    return result;
}

int main() {
    // Create an array of integers and initialize it.
    vector<int> nums = {2, 7, 11, 15};

    // Set the target value.
    int target = 9;

    // Call the twoSum function and store the result in a vector.
    vector<int> result = twoSum(nums, target);

    // Print the result.
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
