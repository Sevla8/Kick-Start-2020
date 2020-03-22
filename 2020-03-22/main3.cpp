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
#include <limits>

int main(int argc, char *argv[]) {
	int T;
	std::cin >> T;

	for (int k = 0; k < T; ++k) {
		int N;
		std::cin >> N;
		int K;
		std::cin >> K;

		std::set<int> M;
		for (int i = 0; i < N; ++i) {
			int tmp;
			std::cin >> tmp;
			M.insert(tmp);
		}

		// std::cout << T << std::endl;
		// std::cout << N << std::endl;
		// std::cout << K << std::endl;
		// for (int i = 0; i < N; ++i) {
		// 	std::cout << M[i] << std::endl;
		// }

		for (int k = 0; k < K; ++k) {
			int max = 0;
			int top;
			int bottom;
			int middle;
			std::set<int>::iterator it = M.begin();
			std::set<int>::iterator jt = M.begin();
			++jt;

			while (jt != M.end()) {
				if (max < *jt - *it) {
					bottom = *it;
					top = *jt;
					middle = (top + bottom) / 2;
					max = *jt - *it;
				}
				++it;
				++jt;
			}
			M.insert(middle);
		}

		int max = 0;
		std::set<int>::iterator it = M.begin();
		std::set<int>::iterator jt = M.begin();
		++jt;

		while (jt != M.end()) {
			if (max < *jt - *it) {
				max = *jt - *it;
			}
			++it;
			++jt;
		}

		std::cout << "Case #" << k+1 << ": " << max << std::endl;
	}

	return 0;
}
