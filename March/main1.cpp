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

int main(int argc, char *argv[]) {
	int T;
	std::cin >> T;

	for (int k = 0; k < T; ++k) {
		int N;
		int B;
		int Ai;
		std::multiset<int> A;

		std::cin >> N;
		std::cin >> B;
		for (int i = 0; i < N; ++i) {
			std::cin >> Ai;
			A.insert(Ai);
		}

		int tmp = 0;
		int count = 0;
		for (std::multiset<int>::iterator it = A.begin(); it != A.end(); ++it) {
			if (tmp + *it <= B) {
				tmp += *it;
				count += 1;
			}
		}
		std::cout << "Case #" << k+1 << ": " << count << std::endl;
	}

	// std::cout << T << std::endl;
	// std::cout << N << std::endl;
	// std::cout << B << std::endl;
	// for (std::set<int>::iterator it = A.begin(); it != A.end(); ++it) {
	// 	std::cout << *it << std::endl;
	// }
	return 0;
}
