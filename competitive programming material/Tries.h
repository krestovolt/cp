#pragma once
class Tries {
private:
	struct trie {
		char chr;
		bool word;
		struct trie* edges[128];
	};
	struct trie* root;
	//trie utility
	struct trie* new_node(const char p);
	//trie functionality
	void push(struct trie* cur, const char* p);
	int delete_key_helper(struct trie* cur, const char* key, int level, int len);

public:
	Tries();
	static bool is_freenode(struct trie* node);
	static bool is_leafnode(struct trie* node);
	int insert(const char* p);
	void delete_key(const char* key);
	int search(const char* key);
};