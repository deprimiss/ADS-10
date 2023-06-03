// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
        char ch;
        std::vector<Node*> vec;
    };
    Node* root;
    std::vector<std::vector<char>> allperms;
    void createallperms(Node* root, std::vector<char> v) {
        if (!(root->ch == ' ')) {
            v.push_back(root->ch);
        }
        if (!root->vec.empty()) {
            for (Node* next : root->vec) {
                createallperms(next, v);
            }
        } else {
            allperms.push_back(v);
        }
    }
    void create(Node* root, const std::vector<char>& in) {
        for (char ch : in) {
            Node* temp = new Node;
            temp->ch = ch;
            root->vec.push_back(temp);
            std::vector<char> ostatok = in;
            ostatok.erase(std::find(ostatok.begin(), ostatok.end(), ch));
            create(temp, ostatok);
        }
    }

 public:
    explicit Tree(std::vector<char> in) {
        root = new Node;
        root->ch = ' ';
        create(root, in);
        std::vector<char> v;
        createallperms(root, v);
    }
    std::vector<std::vector<char>> getAllPerms() const {
        return allperms;
    }
};
#endif  // INCLUDE_TREE_H_
