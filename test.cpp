#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	float exec[32] = { 32, 24, 33, 34, 22, 23, 37, 30, 35, 25, 10, 23, 17, 25, 36, 12, 13, 31, 11, 19, 26, 21, 36, 21, 30, 19, 27, 33, 21, 23, 39, 19 };
	float period[32] = { 3056, 2292, 3152, 3247, 2101, 2197, 3534, 2865, 3343, 2388, 955, 2197, 1623, 2388, 3438, 1146, 1241, 2961, 1050, 1814, 2483, 2005, 3438, 2005, 2865, 1814, 2597, 3152, 2005, 2197, 3725, 1814 };

	cout << exec[25] << " " << period[25] << endl;
	cout << exec[31] << " " << period[31] << endl;

	float sum = 0.0;

	for (int i = 0; i < 32; i++)
		sum += exec[i] / period[i];

	cout << "sum is: " << sum << endl;

	return 0;
}
