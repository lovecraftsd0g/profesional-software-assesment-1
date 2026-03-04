#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ifstream file1("day1_real.txt");

	vector<int> right, left;
	int x, y;
    
	while (file1 >> x >> y) {
		right.push_back(x);
		left.push_back(y);
	}

    /*day 1 part 1*/
	sort(right.begin(), right.end());
	sort(left.begin(), left.end());

	long  total = 0;
	for (int i = 0; i < right.size(); i++) {
		total += abs(right[i] - left[i]);
	}
	cout << "day 1 part 1 answer:" << endl;
	cout << total << endl;
}