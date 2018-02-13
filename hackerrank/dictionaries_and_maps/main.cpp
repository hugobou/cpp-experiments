/* https://www.hackerrank.com/challenges/linkedin-practice-dictionaries-and-maps/problem */

#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<string, string> dict;

class Dictionary {
	public:
		Dictionary();
		void Add(const string& name, const string& number);
		bool HasNumber(const string& name);
		const string& GetNumber(const string& name);
	private:
		map<string, string> dict;
};

Dictionary::Dictionary() : dict()
{
}

void Dictionary::Add(const string& name, const string& number)
{
	dict.insert(make_pair(name, number));
}

bool Dictionary::HasNumber(const string &name)
{
	return dict.count(name) > 0;
}

const string& Dictionary::GetNumber(const string &name)
{
	return dict.find(name)->second;
}

int main()
{
	unsigned int num_inputs = 0;
	string name;
	string number;
	Dictionary dict;

	cin >> num_inputs;

	for (int i = 0; i < num_inputs; i++) {
		cin >> name >> number;
		dict.Add(name, number);
	}

	while (getline(cin, name)) {
		cin >> name;
		if (dict.HasNumber(name)) {
			cout << name << "=" << dict.GetNumber(name) << endl;
		} else {
			if (name.length() != 0) { // Don't print anything when there's an empty line
				cout << "Not found" << endl;
			}
		}
	}

	return 0;
}

