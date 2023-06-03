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
    Node* rt;
    std::vector<std::vector<char>> allpms;
    void create(Node* root, const std::vector<char>& in) {
        for (char ch : in) {
            Node* temp = new Node;
            temp->ch = ch;
            root->vct.push_back(temp);
            std::vector<char> ost = in;
            ost.erase(std::find(ost.begin(), ost.end(), ch));
            create(temp, ost);
        }
    }
    void createallperms(Node* rt, std::vector<char> v) {
        if (!rt->vct.empty()) {
            for (Node* next : rt->vct) {
                createallperms(next, v);
            }
        }
        else {
            allpms.push_back(v);
        }
        if (!(rt->ch == ' ')) {
            v.push_back(rt->ch);
        }
    }

public:
    std::vector<std::vector<char>> getAllPerms() const {
        return allpms;
    }
    explicit Tree(std::vector<char> in) {
        rt = new Node;
        rt->ch = ' ';
        create(rt, in);
        std::vector<char> v;
        createallperms(rt, v);
    }
};
#endif  // INCLUDE_TREE_H_
