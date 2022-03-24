#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using namespace ariel;

class Page{

    private:
    unordered_map<int, unordered_map<int, string>> page;
    const int max_size_of_col = 100;
    int biggest_row = 0;

    public:
    void fill_row(int row);
    bool check_valid_horizontal(int row, int col, int len);
    bool check_valid_vertical(int row, int col, int len);
    void write_horizontal(int row, int column, string wr);
    void write_vertical(int row, int column, string wr);
    void write(int row, int column, Direction dir, string wr);
    string read_horizontal(int row, int col, int len);
    string read_vertical(int row, int col, int len);
    string read(int row, int column, Direction dir, int num_of_chars);
    void erase_horizontal(int row, int col, int len);
    void erase_vertical(int row, int col, int len);
    void erase(int row, int column, Direction dir, int num_of_chars);
    string print_page();
};