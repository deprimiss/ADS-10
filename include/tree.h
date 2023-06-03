// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

class Tree {
private:
    struct Node {
        std::vector<Node*> vct;
        char ch;
    };
    Node* root;
    std::vector<std::vector<char>> allpms;
    void create(Node* rt, const std::vector<char>& v) {
        for (char ch : v) {
            Node* temp = new Node;
            temp->ch = ch;
            rt->vct.push_back(temp);
            std::vector<char> ost = v;
            ost.erase(std::find(ost.begin(), ost.end(), ch));
            create(temp, ost);
        }
    }
    void createallperms(Node* rt, std::vector<char> v) {
        if (!(rt->ch == ' ')) {
            v.push_back(rt->ch);
        }
        if (!rt->vct.empty()) {
            for (Node* next : rt->vct) {
                createallperms(next, v);
            }
        }
        else {
            allpms.push_back(v);
        }
    }

public:
    std::vector<std::vector<char>> getAllPerms() const {
        return allpms;
    }
    explicit Tree(std::vector<char> v) {
        root = new Node;
        root->ch = ' ';
        create(root, v);
        std::vector<char> n;
        createallperms(root, n);
    }
};
#endif  // INCLUDE_TREE_H_
