//Berna Demir 1306170030

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Path {
	string StartP;
	string EndP;
	int length;
}; 

int main() {
	vector <string> node;
	string input;
	cout << "Enter the node's names" << endl;
	cin >> input;
	string start, end, length;
	for (;;) {
		cout << "Enter links (Example: AB5)." << endl << "Enter '0' to finish." << endl;
		cin >> start >> end >> length;
		if (start == "0" | end == "0" | length == "0") {
			break;
		}
		node.push_back(start);
		node.push_back(end);
		node.push_back(length);
	}
	Path* path_list;
	path_list = new Path[node.size()];
	for (int x = 0; node.size(); x++) {

		path_list[0].StartP = node[0][0];
		path_list[1].EndP = node[0][1];
		path_list[2].length = node[0][2];
	}
	
	cout << "Enter a starting node and a budget (Example: A14)" << endl;
	int budget;
	string startingNode;
	cin >> startingNode >> budget;
	int count = 0;
	int lengthh = stoi(length);
	int sum;
	for (sum = 0; sum <= budget ; sum++) {
		if (startingNode == path_list[0].StartP) {
			sum += lengthh;
			count++;
		}
		if (sum > budget) {
			break;
		}
	}
	cout << "Amount of possible paths: "<< sizeof(count) <<endl;

	system("pause");
	return 0;
}