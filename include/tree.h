// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

class Tree {
private:
    struct Node {
        std::vector<Node*> vctr;
        char ch;
    };
    Node* rt;
    std::vector<std::vector<char>> allprms;
    void create(Node* rt, const std::vector<char>& in) {
        for (char ch : in) {
            Node* tmp = new Node;
            tmp->ch = ch;
            rt->vctr.push_back(tmp);
            std::vector<char> ost = in;
            ost.erase(std::find(ost.begin(), ost.end(), ch));
            create(tmp, ost);
        }
    }
    void createallperms(Node* rt, std::vector<char> v) {
        if (!rt->vctr.empty()) {
            for (Node* next : rt->vctr) {
                createallperms(next, v);
            }
        }
        else {
            allprms.push_back(v);
        }
        if (!(rt->ch == ' ')) {
            v.push_back(rt->ch);
        }
    }

public:
    std::vector<std::vector<char>> getAllPerms() const {
        return allprms;
    }
    explicit Tree(std::vector<char> in) {
        rt = new Node;
        rt->ch = ' ';
        std::vector<char> v;
        create(rt, in);
        createallperms(rt, v);
    }
};
#endif  // INCLUDE_TREE_H_
