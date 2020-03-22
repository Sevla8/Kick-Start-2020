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

		std::multiset<std::string> M;
		for (int i = 0; i < N; ++i) {
			std::string tmp;
			std::cin >> tmp;
			M.insert(tmp);
		}

		// std::cout << T << std::endl;
		// std::cout << N << std::endl;
		// std::cout << K << std::endl;
		// for (std::multiset<std::string>::iterator it = M.begin(); it != M.end(); ++it) {
		// 	std::cout << *it << std::endl;
		// }

		int count = 0;
		std::multiset<std::string>::iterator it = M.end();
		while (it-- != M.begin()) {
			std::multiset<std::string>::iterator jt = it;
			++jt;

			std::string str1 = *it;
			std::string str2 = *jt;

			for (int i = 0; i < str1.length(); ++i) {
				if (str1[i] == str2[i]) {
					count++;
				}
				else {
					break;
				}
			}

			++it;
		}

		std::cout << "Case #" << k+1 << ": " << count << std::endl;
	}

	return 0;
}
