#include <iostream>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"


using namespace std;
namespace ariel{

    void Notebook::write(int page, int row, int column, Direction dir, string const &wr){
    }
    string Notebook::read(int page, int row, int column, Direction dir, int num_of_chars){
        return "";
    }
    void Notebook::erase(int page, int row, int column, Direction dir, int num_of_chars){
    }
    void Notebook::show(int page){
    }
}