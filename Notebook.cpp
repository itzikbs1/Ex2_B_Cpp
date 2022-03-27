#include <iostream>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"

// #include "doctest.h"
// #include "Page.cpp"

using namespace std;
using namespace ariel;

const int zero = 0;
const int one_hundred = 100;
// using ariel::Direction;
    

    void Notebook::write(int page, int row, int column, Direction dir, string const &wr){
        if(page < zero || row < zero || column < zero || column >= one_hundred){
            throw runtime_error(std::string("Failed: Illegal argument"));//need to check if this throw okay
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
            throw runtime_error(std::string("Failed: Illegal argument"));//need to check if this throw okay
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

    // int main(){


    // Notebook note;
    // std::string s;
    // for (int i=1; i<10000;i++){s+="a";}
    //  int k=0;
    // for(;k<100;k++){
    //     try{
    //         note.write(0,0,k,Direction::Vertical,s);}
    //     catch(std::exception&){
    //         CHECK_EQ(true,false);
    //     }
    // } 
    //     cout<<"43"<<endl;
    // Notebook n;
    // string s = n.read(50, 50, 50, ariel::Direction::Horizontal, 10);
    // cout<<"read"<<s<<"len:"<<s.length()<<endl;
    // n.erase(50, 20, 60, ariel::Direction::Horizontal, 46);
    // n.write(0,0,0,Direction::Horizontal, "");
    // n.read(10, 10, 10, Direction::Horizontal, 9);
    //     n.show(0);
    //     n.write(0,1,5, Direction::Horizontal, "itzik_");
    //     n.write(0,5,6, Direction::Vertical, "itzik");
    //     n.write(1,0,6, Direction::Horizontal, "Thank you!");

    //     n.show(0);
    //     n.show(1);

    //     return 0;
    // }