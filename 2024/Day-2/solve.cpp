#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

bool check(vector<int>& vals) {
    bool inc = true, dec = true;

    for (int i = 1; i < vals.size(); ++i) {
        int difference = vals[i] - vals[i-1];

        // sanity check for levels
        if (abs(difference) < 1 || abs(difference) > 3) { return false;}

        if (difference > 0) {
            dec = false;
        } else if ( difference < 0) {
            inc = false;
        }
    }
    return inc || dec;
}

int main(void) {
	ifstream file("input.txt");
    int safe=0;
    string line;
	while (std::getline(file, line)) {
        stringstream ss(line);
        vector<int> vals;
        int val;

        while (ss >> val) {
            vals.push_back(val);
        }

        if (check(vals)) {
            safe++;
        }
    }
	file.close();

    cout << "Part 1: " << safe << endl;
}