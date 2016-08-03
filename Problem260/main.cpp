#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    //the lowest method which has o(n) time complexity and worst:o(n/2+1),best:o(1) space complexity
    //well,it is also passed by leetcode OJ (^_^)
    vector<int> singleNumber(vector<int> &nums) {
        vector<int> result;
        map<int, int> map1;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            if (map1.find(nums[i]) == map1.end()) {
                map1[nums[i]] = i;
            } else {
                map1.erase(nums[i]);
            }
        }
        for (it = map1.begin(); it != map1.end(); it++) {
            result.push_back(it->first);
        }
        return result;
    }

    //the neat method which uses bit manipulation
    //simply description:
    //By using XOR all the numbers in the array,we get the result which is the XOR result of the two target numbers
    vector<int> singleNumberByBitMainpulation(vector<int> &nums) {
        int xorALL = 0;
        //xor all numbers
        for (auto num:nums) {
            xorALL ^= num;
        }
        //find the last bit which the two target numbers differ
        int lastBit = ((xorALL - 1) & xorALL) ^xorALL;//00...010...00
        //according to lastBit,we partition all number into two groups
        int a = 0, b = 0;
        for (auto num:nums) {
            if (num & lastBit) { a ^= num; }
            else { b ^= num; }
        }
        return vector<int>{a, b};
    }
};

int main() {
    Solution s;
    int a[] = {-1, 0};
    vector<int> nums(a, a + sizeof(a) / sizeof(int)), r;
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << "  ";
    cout << endl;
    r = s.singleNumberByBitMainpulation(nums);
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << "  ";
    cout << "Hello, World!" << endl;
    return 0;
}