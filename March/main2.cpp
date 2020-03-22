#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <set>
#include <queue>

int main(int argc, char *argv[]) {
	int T;
	std::cin >> T;

	for (int k = 0; k < T; ++k) {
		int N;
		std::cin >> N;
		int K;
		std::cin >> K;
		int P;
		std::cin >> P;

		std::vector<std::queue<int>> list;
		std::vector<std::multiset<int>> set;
		for (int i = 0; i < N; ++i) {
			std::queue<int> sublist;
			std::multiset<int> subset;
			for (int j = 0; j < K; ++j) {
				int tmp;
				std::cin >> tmp;
				sublist.push(tmp);
				subset.insert(tmp);
			}
			list.push_back(sublist);
			set.push_back(subset);
		}

		// std::cout << T << std::endl;
		// std::cout << N << std::endl;
		// std::cout << K << std::endl;
		// std::cout << P << std::endl;
		// for (int i = 0; i < list.size(); ++i) {
		// 	for (int j = 0; j < list[i].size(); ++j) {
		// 		std::cout << list[i][j] << std::endl;
		// 	}
		// }

		int count = 0;
		int left = P;
		while (left > 0) {
			int max = 0;
			int index = 0;
			for (int i = 0; i < list.size(); ++i) {
				if (!list[i].empty()) {
					int tmp = *(set[i].rbegin());
					// std::cout << tmp << std::endl;
					if (max < tmp) {
						max = tmp;
						index = i;
					}
				}
			}
			// std::cout << max << std::endl;
			int tmp = list[index].front();
			// std::cout << tmp << std::endl;
			count += tmp;
			if (!list[index].empty()) {
				set[index].erase(set[index].equal_range(tmp).first);
				list[index].pop();
			}
			left -= 1;
		}
		std::cout << "Case #" << k+1 << ": " << count << std::endl;
	}

	return 0;
}
