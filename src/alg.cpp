// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> allperms = tree.getAllPerms();
    if (!(allperms.size() < n)) {
        return allperms[n - 1];
    }
    return {};
}
