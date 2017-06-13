/*
  The given implementaion only checks if the given key is present in the dictionary or not
*/

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE (26)
#define char_to_index(c) ((int)c-(int)'a')

using namespace std;

struct TrieNode{
	struct TrieNode* children[ALPHABET_SIZE];
	bool isLeaf; //to mark the end of the string
};

struct TrieNode* createNode(){
	struct TrieNode* newNode = new TrieNode;
	
	if(!newNode){
		cout << "Out of memory" << endl;
		return NULL;
	}

	newNode->isLeaf=false;
	for(int i=0;i<ALPHABET_SIZE;i++){
		newNode->children[i]=NULL;
	}
	return newNode;
}

void insertIntoTrie(struct TrieNode* root, const char* key){
	int l = strlen(key),index;
	struct  TrieNode* curr = root;

	for(int i=0;i<l;i++){
		index=char_to_index(key[i]);
		if(!curr->children[index]){
			curr->children[index] = createNode();
		}
		curr = curr->children[index];
	}
	curr->isLeaf=true;
}

int checkIfpresent(struct TrieNode* root, const char* key){
	int l = strlen(key);
	struct TrieNode* cur = root;

	for(int i=0;i<l;i++){
		int index = char_to_index(key[i]);
		if(cur->children[index]==NULL){
			return 0;//key not found return
		}/*this implies there are no words with that prefix*/
		cur = cur->children[index];
	}
  if(cur->isLeaf)
	  return 1;//exact key was found in the dictionary
   return 0;
}

int main(int argc, char const *argv[])
{
	/* code */
	char* key_present[] = {"No such key found","Key is present"};
	struct TrieNode* root = createNode();
	insertIntoTrie(root,"pk");
	insertIntoTrie(root,"kent");
	insertIntoTrie(root,"kem");
	insertIntoTrie(root,"kentucky");
	insertIntoTrie(root,"kips");
	insertIntoTrie(root,"kosta");

	int x = checkIfpresent(root,"ki");
	cout << key_present[x] << endl;	
	x = checkIfpresent(root,"kenil");
	cout << key_present[x] << endl;
	 x = checkIfpresent(root,"kips");
	cout << key_present[x] << endl;
	 x = checkIfpresent(root,"kosta");
	cout << key_present[x] << endl;
	 x = checkIfpresent(root,"lame");
	cout << key_present[x] << endl;
	 x = checkIfpresent(root,"shape");
	cout << key_present[x] << endl;
	return 0;
}
