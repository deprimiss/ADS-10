// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> allprms = tree.getAllPerms();
    if (!(n > allprms.size())) {
        return allprms[--n];
    }
    return {};
}
