#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include "Direction.hpp"
#include <bits/stdc++.h>
#include "Page.hpp"
#include<unistd.h>


using namespace std;
using namespace ariel;

const int min_char = 32;
const int max_char = 126;


    bool Page::check_valid(string str){
        for (unsigned long i = 0; i < str.length(); i++)
        {
            if(str[i] < min_char || str[i] > max_char){
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
        }
        
            if(page[row][col].empty()){
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
                biggest_row = row+i;
            }
            if(page[row+i][col].empty()){
                fill_row(row+i);
            }

            if(page[row+i][col] != "_"){
                return false;
            }
        }
        return true;
    }
    //this function write in row that she get and fill the col wr with size len(wr), Direction:Horizontal
    void Page::write_horizontal(int row, int column, string wr){
        
    if(check_valid_horizontal(row, column, wr.length())){
        for(unsigned long i=0; i<wr.length(); i++){
            page[row][(unsigned long)column + i] = wr[i];
        }
    }else{//already write/erase in this place
        throw runtime_error(std::string("Failed can`t type here again!"));
    }
    }

    //this function write in col that she get and fill the col wr with size len(wr), Direction:Vertical
    void Page::write_vertical(int row, int column, string wr){
            
        if(check_valid_vertical(row, column, wr.length())){
            for(unsigned long i=0; i<wr.length(); i++){
                page[(unsigned long)row+i][column] = wr[i];
            }
        }else{
            throw runtime_error(std::string("Failed can`t type here again!"));

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
                if((int)wr.length() + column >= max_size_of_col){
                    throw runtime_error(std::string("Failed: not valid, the str is too big"));//need to check if this throw okay
                }
                write_horizontal(row, column, wr);

        }else if(dir == Direction::Vertical){
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
        for (int i = 0; i < len; i++)
        {
            text += page[row+i][col];
        }
        return text;
    }
    //this function read from the page
    string Page::read(int row, int column, Direction dir, int num_of_chars){


        string text;
        if(dir == Direction::Horizontal){

            if(row>biggest_row){
            biggest_row = row;
            }
            if(page[row][column].empty()){
            fill_row(row);
            }

            if(num_of_chars + column > max_size_of_col){
                    throw runtime_error(std::string("Failed: not valid, the str is too big"));//need to check if this throw okay
        }

            text = read_horizontal(row, column, num_of_chars);
        
        }else if(dir == Direction::Vertical){
            if(row > biggest_row || num_of_chars > biggest_row){
                biggest_row = row;
                text = fill_vert(num_of_chars);
            }else{
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
        }

            erase_horizontal(row, column, num_of_chars);
        
        }else if(dir == Direction::Vertical){
            erase_vertical(row, column, num_of_chars);
        }
    }
    //this function return string that Represents the page
    string Page::print_page(){
        string s;
        for(int j=0; j<=biggest_row; j++){
            for (int i = 0; i <= max_size_of_col; i++)
            {
                s += page[j][i];
            }
            s += "\n";
        }
        return s;
    }