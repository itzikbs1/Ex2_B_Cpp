#include <iostream>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace std;
using namespace ariel;

const int zero = 0;
const int one_hundred = 100;

    

    void Notebook::write(int page, int row, int column, Direction dir, string const &wr){
        if(page < zero || row < zero || column < zero || column >= one_hundred){
            throw runtime_error(std::string("Failed: Illegal argument"));
        }
        Notebook::notebook[page].write(row, column, dir, wr);
    }

    string Notebook::read(int page, int row, int column, Direction dir, int num_of_chars){
        if(page < zero || row < zero || column < zero || column >= one_hundred || num_of_chars < zero){
            throw runtime_error(std::string("Failed: Illegal argument"));//need to check if this throw okay
        }
        return Notebook::notebook[page].read(row, column, dir, num_of_chars);
    }
    void Notebook::erase(int page, int row, int column, Direction dir, int num_of_chars){
        if(page < zero || row < zero || column < zero || column >= one_hundred || num_of_chars < zero){
            throw runtime_error(std::string("Failed: Illegal argument"));
        }
        Notebook::notebook[page].erase(row, column, dir, num_of_chars);
    }
    void Notebook::show(int page){
        if(page < zero){
            throw runtime_error(std::string("Failed: Illegal argument for page"));
        }
        string s = Notebook::notebook[page].print_page();
        cout<<"The page is:"<<endl<<s<<endl;
    }