import java.util.HashMap;

public class TwoSum {
    public static int[] findTwoSum(int[] nums, int target) {
        // Create a hash map to store each number and its index
        HashMap<Integer, Integer> map = new HashMap<>();
        
        // Loop through the array
        for (int i = 0; i < nums.length; i++) {
            // Calculate the complement needed to reach the target sum
            int complement = target - nums[i];
            
            // If the complement is in the hash map, return its index and the current index
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            
            // Otherwise, add the current number and its index to the hash map
            map.put(nums[i], i);
        }
        
        // If no two numbers add up to the target, return null
        return null;
    }
}
