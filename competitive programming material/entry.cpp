#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "Tries.h"

int trie_driver() {
	try {
		Tries trie = Tries();

		char keys[][8] = { "she", "sells", "sea", "shore", "the", "by", "sheer" };

		for (int i = 0; i < 7; i++)
		{
			trie.insert(keys[i]);
		}

		trie.delete_key(keys[0]);

		printf("%s %s\n", "she", trie.search("she") ? "Present in trie" : "Not present in trie");

		for (int i = 0; i < 7; i++)
		{
			trie.delete_key(keys[i]);
		}
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
		return -1;
	}
	return 0;
}

int main() {
	
	getchar();
	std::string status = trie_driver() == 0 ? "success" : "failed";
	std::cout << "trie driver status: " << status << std::endl;
	return 0;
}
