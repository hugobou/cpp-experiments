#include <iostream>
#include <map>
#include <string>

using namespace std;

class Row {
public:
	int& getValue(int id) {
		return row[id];
	}

	void setValue(int id, int val) {
		this->row.insert(make_pair(id, (val)));
	}

private:
	map<int, int> row;
};

class Section {
public:
	Row& getRow(int id) {
		return section[id];
	}

	void setRow(int id, Row& row) {
		this->section.insert(make_pair(id, row));
	}

private:
	map<int, Row> section;
};

class Plane {
public:
	Section& getSection(int id) {
		return plane[id];
	}

	void setSection(int id, Section& section) {
		this->plane.insert(make_pair(id, section));
	}

private:
	map<int, Section> plane;
};

class Set {
public:
	Plane& getPlane(int id) {
		return set[id];
	}

	void setPlane(int id, Plane& plane) {
		this->set.insert(make_pair(id, plane));
	}

	int getValue(int plane, int section, int row, int pos) {
		int pix =
				this->getPlane(plane).getSection(section).getRow(row).getValue(
						pos);
		cout << "set[" << plane << "][" << section << "][" << row << "][" << pos
				<< "]=" << pix << "\n";
		return pix;
	}

private:
	map<int, Plane> set;
};

Set fillValues(void) {
	int ValuesPerRow = 32;
	int rowsPerSection = 10;
	int sectionsPerPlane = 5;
	int planesPerSet = 2;

	Set set;

	for (int p = 0; p < planesPerSet; p++) {
		Plane plane;
		for (int s = 0; s < sectionsPerPlane; s++) {
			Section section;
			for (int r = 0; r < rowsPerSection; r++) {
				Row row;
				for (int x = 0; x < ValuesPerRow; x++) {
					row.setValue(x, p * 10000 + s * 1000 + r * 100 + x);
				}
				section.setRow(r, row);
			}
			plane.setSection(s, section);
		}
		set.setPlane(p, plane);
	}

	return set;
}

int main(int argc, char *argv[]) {
	Set set = fillValues();

	int foo = set.getValue(0, 1, 2, 3);
	foo = set.getValue(1, 3, 6, 20);

	return 0;

}
