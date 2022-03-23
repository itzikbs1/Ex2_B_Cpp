#include <iostream>
#include <stdlib.h>
#include <string>
#include<algorithm>
#include "Direction.hpp"
#include "Notebook.hpp"
#include "doctest.h"
using namespace ariel;
using namespace std;


//  void write(int page, int row, int column, Direction dir, string wr);
//     string read(int page, int row, int column, Direction dir, int num_of_chars);
//     void erase(int page, int row, int column, Direction dir, int num_of_chars);
//     void show(int page);



TEST_CASE("Good input") {
    Notebook note;
    note.write(0,0,0,Direction::Horizontal,"hello");
	CHECK(note.read(0,0,0,Direction::Horizontal, 5) == "hello");
    note.erase(0,0,0,Direction::Horizontal, 5);
    CHECK(note.read(0,0,0,Direction::Horizontal, 5) == "~~~~~");
    note.write(0,0,6,Direction::Horizontal,"This is a good test!!!");
    CHECK(note.read(0,0,6,Direction::Horizontal, 22) != "This is a good test");
    CHECK(note.read(0,0,6,Direction::Horizontal, 22) == "This is a good test!!!");
    note.write(0,1,0,Direction::Vertical,"hello world");
	CHECK(note.read(0,1,0,Direction::Vertical, 2) == "~h");//check if this good
	CHECK(note.read(0,1,0,Direction::Horizontal, 11) == "hello world");
	CHECK(note.read(1,0,0,Direction::Horizontal, 5) == "_____");
    note.erase(1,0,0,Direction::Horizontal, 5);
    CHECK(note.read(1,0,0,Direction::Horizontal, 5) == "~~~~~");
	CHECK(note.read(0,1,0,Direction::Vertical, 11) != "hello world");
    note.write(0,1,12,Direction::Horizontal,"hi!");
	CHECK(note.read(0,1,12,Direction::Horizontal, 3) == "hi!");
    CHECK(note.read(0,1,0,Direction::Horizontal, 15) == "~~~~~~~~~~~~hi!");
    note.erase(0,1,12,Direction::Horizontal, 3);
	CHECK(note.read(0,1,12,Direction::Horizontal, 3) == "~~~");

}






TEST_CASE("Bad input") {
    Notebook note;
    note.write(0,0,0,Direction::Vertical, "hello world");
	CHECK_THROWS(note.write(0,0,0,Direction::Vertical, "hello"));
    CHECK_THROWS(note.write(0,0,0,Direction::Vertical, "hi"));
    note.erase(0,0,0,Direction::Vertical, 11);
    CHECK_THROWS(note.write(0,0,0,Direction::Vertical, "my name is:"));
    note.write(0,1,0,Direction::Vertical, "hello");
    CHECK_THROWS(note.write(0,1,0,Direction::Vertical, "hi"));
    note.erase(0,1,0,Direction::Vertical, 2);
    CHECK_THROWS(note.write(0,1,0,Direction::Vertical, "itzik"));
    CHECK_THROWS(note.write(0,1,-1,Direction::Vertical, "itzik"));
    CHECK_THROWS(note.write(-12,1,0,Direction::Vertical, "itzik"));
    CHECK_THROWS(note.write(0,-5,0,Direction::Vertical, "itzik"));
    CHECK_THROWS(note.write(-1,-1,-1,Direction::Vertical, "itzik"));
    note.write(0,0,0,Direction::Horizontal, "hello world");
    CHECK_THROWS(note.erase(0,1,0,Direction::Vertical, -11));
    note.erase(0,0,0,Direction::Vertical, 11);
    CHECK_THROWS(note.write(0,0,0,Direction::Vertical, "hi!"));
    CHECK_THROWS(note.write(0,0,0,Direction::Horizontal, "hi!"));
    note.erase(0,0,0,Direction::Horizontal, 11);
    CHECK_THROWS(note.write(0,100,50,Direction::Horizontal, "hello worldhello worldhello worldhello worldhello worldhello worldhello worldhello worldhello worldhello world"));
    CHECK_THROWS(note.write(0,0,-1,Direction::Horizontal, "hi!"));
    CHECK_THROWS(note.write(0,-2,0,Direction::Horizontal, "hi!"));
    CHECK_THROWS(note.write(-3,0,0,Direction::Horizontal, "hi!"));
    CHECK_THROWS(note.write(-1,-1,-1,Direction::Vertical, "hi!"));

}