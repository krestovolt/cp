
//Tries implementation
#include "Tries.h"
#include <cstdlib>
#include <string>

#define root Tries::root
#define FREE(ptr)\
	free(ptr);\
	ptr=NULL;

Tries::Tries() {
	root = 0;
	root = Tries::new_node(' ');
}

struct Tries::trie* Tries::new_node(const char p) {
	struct Tries::trie* node = (struct Tries::trie*) malloc(sizeof(struct Tries::trie));
	if (node) {
		node->chr = p;
		node->word = false;
		for (size_t i = 0; i < 128; ++i)
			node->edges[i] = 0;
	}
	return node;
}


void Tries::push(struct Tries::trie* cur, const char* p) {
	int len = strlen(p);
	struct Tries::trie* _cur = cur;

	for (int level = 0; level < len; ++level) {
		if (_cur->edges[p[level]] == 0)
			_cur->edges[p[level]] = new_node(p[level]);
		_cur = _cur->edges[p[level]];
	}
	_cur->word = true;
}

int Tries::insert(const char* p) {
	Tries::push(root, p);
	return 1;
}

bool Tries::is_freenode(struct trie* node) {
	for (int i = 0; i < 128; ++i)
		if (node->edges[i] != 0)
			return false;
	return true;
}

bool Tries::is_leafnode(struct trie* node) {
	return node->word;
}

int Tries::delete_key_helper(struct Tries::trie* cur, const char* key, int level, int len) {
	if (cur) {
		//base case
		if (level == len) {
			cur->word = false;
			cur->chr = ' ';
			if (Tries::is_freenode(cur))
				return 1;
			return 0;
		}
		else {
			if (Tries::delete_key_helper(cur->edges[key[level]], key, level + 1, len) == 1){
				FREE(cur->edges[key[level]]);

				return (!Tries::is_leafnode(cur) && Tries::is_freenode(cur));
			}
		}
	}
	return 0;
}

void Tries::delete_key(const char* key)
{
	int len = strlen(key);

	if (len > 0)
	{
		Tries::delete_key_helper(root, key, 0, len);
	}
}

int Tries::search(const char* key) {
	int len = strlen(key);
	struct Tries::trie* _cur = root;

	for (int level = 0; level < len; ++level) {
		if (_cur->edges[key[level]] == 0)
			return 0;
		_cur = _cur->edges[key[level]];
	}
	return 0;
}




