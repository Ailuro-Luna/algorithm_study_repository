// https://neetcode.io/problems/implement-prefix-tree
#include <bits/stdc++.h>
using namespace std;

class PrefixTree {
public:
    PrefixTree() {
        for(auto &child :children) {
            child = NULL;
        }
        is_end_of_word = false;
    }
    
    void insert(string word) {
        PrefixTree* current = this;
        for(char ch:word) {
            int i = ch-'a';
            if(current->children[i]==NULL) {
                current->children[i]=new PrefixTree();
            }
            current=current->children[i];
        }
        current->is_end_of_word=true;
    }
    
    bool search(string word) {
        PrefixTree* current = this;
        for(char ch:word) {
            int i = ch-'a';
            if(current->children[i]==NULL) {
                return false;
            } else {
                current=current->children[i];
            }
        }
        return current->is_end_of_word;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* current = this;
        for(char ch:prefix) {
            int i = ch-'a';
            if(current->children[i]==NULL) {
                return false;
            } else {
                current=current->children[i];
            }
        }
        return true;
    }

private:
    PrefixTree* children[26];
    bool is_end_of_word;
};
