#include <iostream>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"
#include "Page.cpp"

using namespace std;
using namespace ariel;
// using ariel::Direction;
    

    void Notebook::write(int page, int row, int column, Direction dir, string const &wr){
        if(page < 0 || row < 0 || column < 0 || column > 100 || wr.length() > 100){
            throw runtime_error(std::string("Failed: Illegal argument"));//need to check if this throw okay
        }
        Notebook::notebook[page].write(row, column, dir, wr);
    }

    string Notebook::read(int page, int row, int column, Direction dir, int num_of_chars){
        if(page < 0 || row < 0 || column < 0 || column > 100 || num_of_chars < 0 || num_of_chars > 100){
            throw runtime_error(std::string("Failed: Illegal argument"));//need to check if this throw okay
        }
        return Notebook::notebook[page].read(row, column, dir, num_of_chars);
    }
    void Notebook::erase(int page, int row, int column, Direction dir, int num_of_chars){
        if(page < 0 || row < 0 || column < 0 || column > 100 || num_of_chars < 0 || num_of_chars > 100){
            throw runtime_error(std::string("Failed: Illegal argument"));//need to check if this throw okay
        }
        Notebook::notebook[page].erase(row, column, dir, num_of_chars);
    }
    void Notebook::show(int page){
        if(page < 0){
            throw runtime_error(std::string("Failed: Illegal argument for page"));
        }
        string s = Notebook::notebook[page].print_page();
        cout<<"The page is:"<<endl<<s<<endl;
    }

    int main(){

        cout<<"43"<<endl;
        Notebook n;
        n.write(0,0,0,Direction::Horizontal, "");

        n.show(0);
        n.write(0,0,5, Direction::Horizontal, "itzik_");
        n.write(0,1,6, Direction::Vertical, "itzik");
        n.write(1,1,6, Direction::Horizontal, "Thank you!");

        n.show(0);
        n.show(1);

        return 0;
    }