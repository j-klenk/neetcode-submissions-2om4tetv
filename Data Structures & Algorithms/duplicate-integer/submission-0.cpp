class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set<int> numbers;

        for(int element : nums)
        {
            if(numbers.count(element) == 1)
                return true;

            numbers.insert(element);
        }

        return false;
    }
};