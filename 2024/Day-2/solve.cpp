#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

bool check_one(vector<int>& vals) {
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

bool check_two(vector<int>& vals) {
    if (check_one(vals)) {
        return true;
    }

    for ( int i = 0; i < vals.size(); ++i) {
        vector<int> new_vals;
        for (int j = 0; j < vals.size(); ++j) {
            if (j != i) {
                new_vals.push_back(vals[j]);
            }
        }
        if (check_one(new_vals)) {
            return true;
        }
    }
    return false;
}

int main(void) {
	ifstream file("input.txt");
    int part_one=0, part_two=0;
    string line;
	while (std::getline(file, line)) {
        stringstream ss(line);
        vector<int> vals;
        int val;

        while (ss >> val) {
            vals.push_back(val);
        }

        if (check_one(vals)) {
            part_one++;
        }

        if (check_two(vals)) {
            part_two++;
        }
    }
	file.close();

    cout << "Part 1: " << part_one << endl;
    cout << "Part 2: " << part_two << endl;
}