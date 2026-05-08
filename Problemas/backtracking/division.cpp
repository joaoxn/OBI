//
// Created by xnaxg on 02/04/2026.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int nums[] = {0,1,2,3,4,5,6,7,8,9};

        vector<pair<int,int>> solutions;
        bool skip = false;
        int prev = 4;
        do {
            if (skip && nums[4] == prev) {
                int min = 10;
                int pos = -1;
                for (int i = 5; i < 10; i++) {
                    if (nums[i] > nums[4] && nums[i] < min) {
                        min = nums[i];
                        pos = i;
                    }
                }
                nums[pos] = nums[4];
                nums[4] = min;
                sort(nums+5, nums+10);
                // while (nums[4] == prev && next_permutation(nums, nums+10)) {
                //     continue;
                // }
                skip = false;
            }
            prev = nums[4];
            double numerator = 0;
            int denominator = 0;
            for (int i = 0; i < 5; i++) {
                numerator = numerator * 10 + nums[i];
                denominator = denominator * 10 + nums[i+5];
            }
            if (numerator/denominator == n) {
                solutions.emplace_back(numerator,denominator);
                skip = true;
            }
        } while (next_permutation(nums, nums+10));

        if (solutions.empty()) {
            cout << "There are no solutions for "<< n << ".\n\n";
            continue;
        }
        for (auto &pair : solutions) {
            printf("%05d / %05d = %d\n", pair.first, pair.second, n);
        }
        cout << "\n";
    }
}
