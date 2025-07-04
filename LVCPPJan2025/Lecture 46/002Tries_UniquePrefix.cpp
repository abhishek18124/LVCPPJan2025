#include<iostream>
#include<map>

using namespace std;

class node {

public :

	char ch;
	bool terminal;
	map<char, node*> childMap;
	int freq;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
		this->freq = 0;
	}

};

class trie {
	node* root;

public :

	trie() {
		root = new node('#');
	}

	// time : O(len of str.log26) ~ O(len of str)

	void insert(string str) {
		node* cur = root;
		for (char ch : str) {
			if (cur->childMap.find(ch) == cur->childMap.end()) {
				node* n = new node(ch);
				cur->childMap[ch] = n;
			}
			cur = cur->childMap[ch];
			cur->freq++;
		}
		cur->terminal = true;
	}

	// time : O(len of str.log26) ~ O(len of str)

	string shortestUniquePrefix(string str) {
		node* cur = root;
		string ans = "";
		for (char ch : str) {
			cur = cur->childMap[ch];
			ans += ch;
			if (cur->freq == 1) {
				return ans;
			}
		}
		return ""; // str has no unique prefix
	}

};


int main() {

	string words[] = {"code", "coder", "coding", "new", "neon"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	for (string word : words) {
		cout << "uniquePrefix(" << word << ") = " << t.shortestUniquePrefix(word) << endl;
	}

	return 0;
}