#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    int countHillValley(std::vector<int> &nums) {
        const int n = static_cast<int>(nums.size());

        std::stack<int> stack;
        int prev_smaller[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && nums[i] < nums[stack.top()]) {
                prev_smaller[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            prev_smaller[stack.top()] = -1;
            stack.pop();
        }

        int next_smaller[n];
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && nums[i] < nums[stack.top()]) {
                next_smaller[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            next_smaller[stack.top()] = n;
            stack.pop();
        }

        int prev_larger[n];
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && nums[i] > nums[stack.top()]) {
                prev_larger[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            prev_larger[stack.top()] = -1;
            stack.pop();
        }

        int next_larger[n];
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && nums[i] > nums[stack.top()]) {
                next_larger[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        while (!stack.empty()) {
            next_larger[stack.top()] = n;
            stack.pop();
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (prev_smaller[i] > prev_larger[i] && next_smaller[i] < next_larger[i] // hill
                || prev_larger[i] > prev_smaller[i] && next_larger[i] < next_smaller[i]) { // valley
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    std::vector<int> data = {2, 4, 1, 1, 6, 5};
    Solution sol;
    const int result = sol.countHillValley(data);
    std::cout << result;
    return 0;
}