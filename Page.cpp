#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
// #include "Notebook.cpp"
#include <bits/stdc++.h>
#include "Page.hpp"
#include<unistd.h>


// #include "doctest.h"
using namespace std;
using namespace ariel;


// const int max_size_of_col = 100;
// int biggest_row = 0;
    // class Page{
    // public:
    //             horizonal/vertical      vertical/horizonal
    //unordered_map<row/col, unordered_map<col/row, string>> page;
    // unordered_map<int, unordered_map<int, string>> page;
    
    //fill the specific row in _______...

    bool Page::check_valid(string str){
        for (unsigned long i = 0; i < str.length(); i++)
        {
            if(str[i] < 32 || str[i] > 126){
                return false;
            }
        }
        return true;
    }

    void Page::fill_row(int row){
        for (int i = 0; i < max_size_of_col; i++)
        {
            page[row][i] = '_';
        }
    }
    void Page::fill_page(int big_row, int max){
        for(int j=big_row; j<max; j++){
        for (int i = 0; i < max_size_of_col; i++)
        {
            page[j][i] = "_";
        }
        }
    }
    int max(int len1, int len2){
        int max;
        if(len1>len2){
            max=len1;
        }else{
            max=len2;
        }
        return max;
    }
    string Page::fill_vert(int len){
        string s;
        for (int i = 0; i < len; i++)
        {
            s += "_";
        }
        return s;
    }
    //this function check if in this row not write yet, return true or false
    bool Page::check_valid_horizontal(int row, int col, int len){

        for (int i = 0; i < len; i++)
        {
            if(row>biggest_row){
                biggest_row = row;
                // cout<<"100"<<endl;
                // fill_row(row);
        }
        
            if(page[row][col].empty()){
                // cout<<"105"<<endl;
                fill_row(row);
            }

            if(page[row][col+i] != "_"){
                return false;
            }
        }
        return true;
    }
    //this function check if in this col not write yet,
    //if the row dosent exsist ("") then create new one,  return true or false
    bool Page::check_valid_vertical(int row, int col, int len){
        for (int i = 0; i < len; i++)
        {
            if(row+i>biggest_row){
                // cout<<"83"<<endl;
                // cout<<"big+row:"<<biggest_row<<endl;
                // cout<<"row+i:"<<row+i<<endl;
                biggest_row = row+i;
            }
            // cout<<"page: "<<page[row+i][col]<<endl;
            if(page[row+i][col].empty()){
                // cout<<"41"<<endl;
                //  cout<<"91"<<endl;
                fill_row(row+i);
            }

            if(page[row+i][col] != "_"){
                // cout<<"46"<<endl;
                //  cout<<"97"<<endl;
                return false;
            }
        }
        return true;
    }
    //this function write in row that she get and fill the col wr with size len(wr), Direction:Horizontal
    void Page::write_horizontal(int row, int column, string wr){
        
    if(check_valid_horizontal(row, column, wr.length())){
        for(unsigned long i=0; i<wr.length(); i++){
            // cout<<"w[i]"<<w[i]<<endl;
            page[row][(unsigned long)column + i] = wr[i];
        }
    }else{//already write/erase in this place
        throw runtime_error(std::string("Failed can`t type here again!"));//need to check if this throw okay
        // throw("can`t type in this place again");
    }
    }

    //this function write in col that she get and fill the col wr with size len(wr), Direction:Vertical
    void Page::write_vertical(int row, int column, string wr){
            
        if(check_valid_vertical(row, column, wr.length())){
            // cout<<"wr.size"<<wr.length()<<endl;
            // cout<<"row "<<row<<endl;
            // cout<<"col "<<column<<endl;
            for(unsigned long i=0; i<wr.length(); i++){
                // page[row+i][column].insert(1,wr);
                page[(unsigned long)row+i][column] = wr[i];
            }
        }else{//already write/erase in this place
            // cout<<"71"<<endl;
            throw runtime_error(std::string("Failed can`t type here again!"));//need to check if this throw okay
            // __throw_bad_exception;
            // __throw_invalid_argument;
            // throw("can`t type in this place again");
        }
        }
    bool contain_in_text(string str){
        for (unsigned long i = 0; i < str.length(); i++)
        {
            char c = str.at(i);
            if(c == '~'){
                return false;
            }
        }
        return true;
    }

    //this function write to the page and check if its valid text
    void Page::write(int row, int column, Direction dir, string const &wr){

        if(!check_valid(wr)){
            throw runtime_error(std::string("Failed can`t type here again!"));
        }

        if(!contain_in_text(wr)){
            throw runtime_error(std::string("Failed can`t write ~ in the page!"));//need to check if this throw okay
        }

        if(dir == Direction::Horizontal){//Horizontal
                // cout<<"wr:"<<wr.size()<<endl;
                // cout<<"col:"<<column<<endl;
                // cout<<"max:"<<max_size_of_col<<endl;
                if((int)wr.length() + column >= max_size_of_col){
                    throw runtime_error(std::string("Failed: not valid, the str is too big"));//need to check if this throw okay
                    // throw("not valid, the str is too big");
                }
                write_horizontal(row, column, wr);

        }else if(dir == Direction::Vertical){

            // int temp = max(row, column);
            // int m = max(temp, wr.length());

            // fill_page(biggest_row ,m);
            // if(wr.length() > max_size_of_col){
            //         throw("not valid, the str is too big");
            //     }
                write_vertical(row, column, wr);
        }
    }
    //this function read from specific row len characters to string and return the string 
    string Page::read_horizontal(int row, int col, int len){
        string text;
        for (int i = 0; i < len; i++)
        {
            text += page[row][col+i];
        }
        return text;
    }

    //this function read from specific col len characters to string and return the string
    string Page::read_vertical(int row, int col, int len){
        string text;

        // if(row < biggest_row){
        //     for (int i = 0; i < len; i++)
        //     {
        //         text += "_";
        //     }
            
        // }else{
        for (int i = 0; i < len; i++)
        {
            text += page[row+i][col];
        }
        // }
        return text;
    }
    //this function read from the page
    string Page::read(int row, int column, Direction dir, int num_of_chars){


        string text;
        if(dir == Direction::Horizontal){

            if(row>biggest_row){
            biggest_row = row;
            // fill_row(row);
            }
            if(page[row][column].empty()){
            // cout<<"105"<<endl;
            fill_row(row);
            }

            if(num_of_chars + column > max_size_of_col){
                    throw runtime_error(std::string("Failed: not valid, the str is too big"));//need to check if this throw okay
                    // throw("not valid, the str is too big");
        }

            text = read_horizontal(row, column, num_of_chars);
        
        }else if(dir == Direction::Vertical){
            if(row > biggest_row || num_of_chars > biggest_row){
                biggest_row = row;
                text = fill_vert(num_of_chars);
            
            }else{
            // if(num_of_chars > biggest_row){
            //     fill_row();
            // }
            text = read_vertical(row, column, num_of_chars);
        }
        }
        return text;
    }
    //this function erase spesific row in ~
    void Page::erase_horizontal(int row, int col, int len){
        for(int i=0; i<len; i++){
            page[row][col+i] = "~";
        }
    }
    //this function erase spesific col in ~
    void Page::erase_vertical(int row, int col, int len){
        for(int i=0; i<len; i++){
            page[row+i][col] = "~";
        }
    }

    //this function erase place in the page with ~
    void Page::erase(int row, int column, Direction dir, int num_of_chars){

        if(row>biggest_row){
            biggest_row = row;
        }


        if(dir == Direction::Horizontal){

        if(num_of_chars + column > max_size_of_col){
                throw runtime_error(std::string("Failed: not valid, the str is too big"));//need to check if this throw okay
                // throw("not valid, the str is too big");
        }

            erase_horizontal(row, column, num_of_chars);
        
        }else if(dir == Direction::Vertical){
            erase_vertical(row, column, num_of_chars);
        }
    }
    //this function return string that Represents the page
    string Page::print_page(){//for me
        string s;
        // cout<<"153"<<endl;
        for(int j=0; j<=biggest_row; j++){
            // cout<<"biggest row: "<<biggest_row<<endl;
            for (int i = 0; i <= max_size_of_col; i++)
            {
                // cout<<"158"<<endl;
                // cout<<"page[j][i] = "<<page[j][i]<<endl;
                s += page[j][i];
            }
            s += "\n";
        }
        return s;
    }

// int main(){


//     //  Notebook note;
//      Page p;
//     std::string s;
//     for (int i=1; i<10000;i++){s+="a";}
//      int k=0;
//     for(;k<100;k++){
//         // try{
//             p.write(0,k,Direction::Vertical,s);
//             // }
//         // catch(std::exception&){
//         //     CHECK_EQ(true,false);
//         // }
//     } 
//     string str = p.print_page();
//     cout<<str<<endl;

    // Page p = new Page();
    // cout<<"221"<<endl;
    // ariel::Page p = new ariel::Page();
    // Page p;
    // p.write(0,0,ariel::Direction::Horizontal, "");
    // write(0,0,ariel::Direction::Horizontal, "");
    // string s = ariel::write(0,0,ariel::Direction::Horizontal, "");
    // s += "pin";
    // cout<<"the string is: "<<p.print_page()<<endl;
    // arielwrite(0,5, ariel::Direction::Horizontal, "itzik_");
    // p.write(1,6, ariel::Direction::Vertical, "itzik");
    // cout<<ariel::print_page()<<endl;
    // usleep(10000);
    // ariel::write(0,10, ariel::Direction::Horizontal, " ben shushan");
    // cout<<ariel::print_page()<<endl;
    // cout<<ariel::page[0][5]<<endl;
    // cout<<ariel::page[1][1]<<endl;
    // ariel::erase(1, 5, ariel::Direction::Horizontal, 100);
    // cout<<"after erase"<<ariel::page[0][1]<<endl;
    // cout<<"after erase"<<ariel::page[0][2]<<endl;
    // cout<<"after erase"<<ariel::page[0][3]<<endl;
    // cout<<"after erase"<<ariel::page[0][4]<<endl;
    // 
    // cout<<ariel::print_row(1)<<endl;
//     return 0;
// }