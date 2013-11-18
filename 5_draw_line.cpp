#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void draw_line(vector<int> &screen, int width, int x1, int x2, int y) {
		int start_offset = x1 % 8;
		int first_full_byte = x1 / 8;
		if (start_offset != 0) {
			first_full_byte++;
		}

		int end_offset = x2 % 8;
		int last_full_byte = x2 / 8;
		if (end_offset != 0) {
			last_full_byte--;
		}		

		for (int b = first_full_byte; b <= last_full_byte; b++) {
			screen[(width / 8) * y + b] = 0xFF;
		}

		int start_mask = (0xff >> start_offset);
		int end_mask = ~(0xff >> (end_offset+1));

		if ((x1 / 8) == (x2 / 8)) {  // same byte
			int mask = (start_mask & end_mask);
			screen[(width/8)*y+(x1/8)] |= mask;
		} else {
			if (start_offset != 0) {
				int byte_number = (width / 8) * y + first_full_byte - 1;
				screen[byte_number] |= start_mask;
			}
			if (end_offset != 0) {
				int byte_number = (width / 8) * y + last_full_byte + 1;
				screen[byte_number] |= end_mask;
			}
		}
	}

};

int main()
{
	Solution sol;
	vector<int> screen(240, 0);

	// hard to generate test cases. Ideas?

	return 0;
}
