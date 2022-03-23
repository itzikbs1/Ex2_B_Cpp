#include <iostream>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"

using namespace std;
namespace ariel{

class Notebook{

    public:
    void write(int page, int row, int column, Direction dir, string const &wr);
    string static read(int page, int row, int column, Direction dir, int num_of_chars);
    void erase(int page, int row, int column, Direction dir, int num_of_chars);
    void show(int page);
};
}