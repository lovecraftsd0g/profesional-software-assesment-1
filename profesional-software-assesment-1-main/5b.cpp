#include <iostream>
#include <fstream>
#include <chrono>
#include <regex>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <sstream>

using namespace std;
int main(){
	/*day 5 part 1*/
	
	ifstream file5("day5_real.txt");
	regex pattern(R"((\d{2})\|(\d{2}))");
	string Day5String;
	unordered_map<int, unordered_set<int>> pairs;
	string line;

	int total = 0;

	sregex_iterator begin(Day5String.begin(), Day5String.end(), pattern);
	sregex_iterator end;

	/*this section searches for pairsand patterns*/
	while (getline(file5, line) && !line.empty()) {
		smatch match;
		if (regex_search(line, match, pattern)) {
			pairs[stoi(match[1])].insert(stoi(match[2]));
		}
	}


    /*this section checks the pages and adds the middle page to the total if its valid*/
    while (getline(file5, line)) {

       if(line.empty()){
			continue;
	   }

	   vector<int> pages;
	   stringstream ss(line);
	   string number;
	   bool valid = true;

	   /*appendall pages from the line*/
	   while(getline(ss, number, ',')) {
		   pages.push_back(stoi(number));
	   }
	   if (pages.empty()){
		   continue;
	   }
	   for (int i = 0; i < pages.size() && valid; i++) {
		   for (int j = i + 1; j < pages.size(); j++) {
			   int later = pages[j];
			   int earlier = pages[i];
			   if (pairs[later].count(earlier)) {
				   valid = false;
				   break;
			   }
		   }
	   }
	   if(!valid){
		   total += pages[pages.size() / 2];
	   }
    }

	cout << "Day 5 Part 2" << endl;
	cout << total << endl;
}