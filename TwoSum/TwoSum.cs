using System;
using System.Collections.Generic;

class Solution {
    static void Main(string[] args) {
        // Define the input array and target
        int[] nums = { 2, 7, 11, 15 };
        int target = 9;
        
        // Create a dictionary to store previously seen numbers
        Dictionary<int, int> numDict = new Dictionary<int, int>();
        
        // Iterate through the array
        for (int i = 0; i < nums.Length; i++) {
            // Check if the complement of the current number exists in the dictionary
            int complement = target - nums[i];
            if (numDict.ContainsKey(complement)) {
                // If the complement exists, return the indices
                int complementIndex = numDict[complement];
                Console.WriteLine("Indices: [{0}, {1}]", complementIndex, i);
                return;
            }
            
            // If the complement does not exist, add the current number and its index to the dictionary
            numDict[nums[i]] = i;
        }
    }
}
