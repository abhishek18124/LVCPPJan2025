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
	int n; // to track no. of words or strings present in the trie

public :

	trie() {
		root = new node('#');
		n = 0; // init trie is empty, there are no words or strings
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
		n++; // since we've added a new string or word to the trie
	}

	// time : O(len of str)

	string longestCommonPrefix(string str) {
		node* cur = root;
		string ans = "";
		for (char ch : str) {
			cur = cur->childMap[ch];
			if (cur->freq != n) {
				break;
			}
			ans += ch; // cur node is shared by all the words in the trie so we can add ch to the common prefix we are building
		}
		return ans;
	}

};


int main() {

	string words[] = {"abc", "abcd", "abcde", "xyz"};

	trie t;
	for (string word : words) {
		t.insert(word);
	}

	cout << t.longestCommonPrefix(words[0]) << endl;

	return 0;
}