#include <fstream>
#include <vector>

using namespace std;


class HashTable {
private:
	vector<int> table;
	const int c;            //h(x, i) = ((x mod m) + c ⋅ i) mod m
public:
	HashTable(int size, int c) : c{ c } {
		table.resize(size, -1);
	}
	void insert(int x) {
		if (!this->contains(x)) {
			int i = 1;
			int pos = x % table.size();
			while (table[pos] != -1) {
				pos = (x % table.size() + c * i) % table.size();
				i++;
			}
			table[pos] = x;
		}
	}
	bool contains(int x) {
		int i = 1;
		int pos = x % table.size();
		while (table[pos] != -1) {
			if (table[pos] == x)
				return true;
			pos = (x % table.size() + c * i) % table.size();
			i++;
		}
		return false;
	}
	vector<int> getTable() {
		return this->table;
	}
};

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int m, c, n;
	in >> m >> c >> n;
	HashTable table(m, c);
	int tmp_input;
	while (in >> tmp_input)
		table.insert(tmp_input);
	auto res = table.getTable();
	for (auto& i : res) {
		if (i == -1)
			out << -1 << ' ';
		else
			out << i << ' ';
	}
}