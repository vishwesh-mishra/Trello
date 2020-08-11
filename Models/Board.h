#include<string>
#include<vector>
#include<map>

using namespace std;

class Board {
public:
	int id;
	string name, privacy, url;
	map<string,bool> members;
	vector<int> lists;
	Board(int id, string name, string privacy, string url, map<string,bool> members, vector<int> lists) {
		this->id = id;
		this->name = name;
		this->privacy = privacy;
		this->url = url;
		this->members = members;
		this->lists = lists;
	}
};
