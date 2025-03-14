#include <fstream>

using namespace std;

int main() {
	long long n;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> n;
	int ost = 0;
	int count = 0;
	while (n != 0) {
		ost = n % 2;
		if (ost == 1)
			out << count << '\n';
		count++;
		n /= 2;
	}
}