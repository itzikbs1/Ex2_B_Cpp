#include <iostream>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
#include <bits/stdc++.h>
#include <unordered_map>
#include "Page.hpp"


using namespace std;
namespace ariel{

class Notebook{

    private:
    unordered_map<int, Page> notebook;

    public:
    void write(int page, int row, int column, Direction dir, string const &wr);
    string read(int page, int row, int column, Direction dir, int num_of_chars);
    void erase(int page, int row, int column, Direction dir, int num_of_chars);
    void show(int page);
};
}