#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int d, vf, vg;
	vector<char> p;
    while (cin >> d >> vf >> vg) {
        
        double dist= sqrt(12.0 * 12.0 + d * d);
		double temp_f = 12.0 / vf;
        double temp_g = dist / vg;
      
        if (temp_g <= temp_f) {
            p.push_back('S');
        } else {
            p.push_back('N');
        }
    }

    for(int i=0; i < p.size(); i++){
	cout << p[i] << endl;
    }

    return 0;
}
