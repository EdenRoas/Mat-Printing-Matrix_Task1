#include "doctest.h"
#include "mat.hpp"

using namespace ariel;
#include <string>
#include <algorithm>

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Bad input")
{
    CHECK_THROWS(mat(0, 0, '@', '*')); //1-Empty mat
    CHECK_THROWS(mat(0, 7, '@', '*')); //2-First num = 0
    CHECK_THROWS(mat(0, 0, '@', '*')); //3-Seconde num = 0
    CHECK_THROWS(mat(2, 7, '@', '*')); //4-First num even
    CHECK_THROWS(mat(3, 10,'@', '*')); //5-First num are negative & second num are even
    CHECK_THROWS(mat(7, 9, '@', '*')); //6-Both numbers negative
    CHECK_THROWS(mat(3, 1, '$', '%')); //7-Second number negative
    CHECK_THROWS(mat(1, 3, '$', '%')); //8-First number negative
    CHECK_THROWS(mat(7, 2, '@', '*')); //9-The second num even
    
    
}

TEST_CASE("Good input") 
{
    CHECK(nospaces(mat(1, 3, '$', '-')) == nospaces("$\n"   //10
                                                    "$\n"
                                                    "$"));

	CHECK(nospaces(mat(9, 7, '@', '*')) ==nospaces( "@@@@@@@@@\n"     //11
								                    "@*******@\n"
							                        "@*@@@@@*@\n"
								                    "@*@***@*@\n"
								                    "@*@@@@@*@\n"
								                    "@*******@\n"
								                    "@@@@@@@@@"));
    
    CHECK(nospaces(mat(13,5,'$','*'))==nospaces("$$$$$$$$$$$$$\n"     //12
                                                "$***********$\n"
                                                "$*$$$$$$$$$*$\n"
                                                "$***********$\n"
                                                "$$$$$$$$$$$$$"));

    CHECK(nospaces(mat(1, 1, '#', '@')) == nospaces("#")); //13

    CHECK(nospaces(mat(3, 5, 'X','O')) == nospaces( "XXX\n" //14
                                                    "XOX\n"
                                                    "XOX\n"
                                                    "XOX\n"
                                                    "XXX"));
          
    CHECK(nospaces(mat(19, 19, '#', '*')) == nospaces(  "###################\n" //15
                                                        "#*****************#\n"
                                                        "#*###############*#\n"
                                                        "#*#*************#*#\n"
                                                        "#*#*###########*#*#\n"
                                                        "#*#*#*********#*#*#\n"
                                                        "#*#*#*#######*#*#*#\n"
                                                        "#*#*#*#*****#*#*#*#\n"
                                                        "#*#*#*#*###*#*#*#*#\n"
                                                        "#*#*#*#*#*#*#*#*#*#\n"
                                                        "#*#*#*#*###*#*#*#*#\n"
                                                        "#*#*#*#*****#*#*#*#\n"
                                                        "#*#*#*#######*#*#*#\n"
                                                        "#*#*#*********#*#*#\n"
                                                        "#*#*###########*#*#\n"
                                                        "#*#*************#*#\n"
                                                        "#*###############*#\n"
                                                        "#*****************#\n"
                                                        "###################"));
    
    CHECK(nospaces(mat(3, 7, '&', '*')) == nospaces("&&&\n" //16
                                                    "&*&\n"
                                                    "&*&\n"
                                                    "&*&\n"
                                                    "&*&\n"
                                                    "&*&\n"
                                                    "&&&"));

    CHECK(nospaces(mat(5, 5, '!', '-')) == nospaces("*******\n" //17
													"!---!\n"
													"!-!-!\n"
												    "!---!\n"
												    "*******"));

     CHECK(nospaces(mat(7, 7, '*', '*')) ==nospaces("*******\n" //18
                                                    "*******\n"
                                                    "*******\n"
                                                    "*******\n"
                                                    "*******"));
}
TEST_CASE("Incorrect answer") 
{
    CHECK(nospaces(mat(19, 19, '#', '*')) != nospaces(   "###################\n" //19
                                                                "#*****************#\n"
                                                                "#*###############*#\n"
                                                                "#*#*************#*#\n"
                                                                "#*#*###########*#*#\n"
                                                                "#*#*#*********#*#*#\n"
                                                                "#*#*#*#######*#*#*#\n"
                                                                "#*#*#*#*****#*#*#*#\n"
                                                                "#*#*#*#*###*#*#*#*#\n"
                                                                "#*#*#*#*#*#*#*#*#*#\n"
                                                                "#*#*#*#*#*#*#*#*#*#\n" //in the middle it supposed ### instead of #*#
                                                                "#*#*#*#*****#*#*#*#\n"
                                                                "#*#*#*#######*#*#*#\n"
                                                                "#*#*#*********#*#*#\n"
                                                                "#*#*###########*#*#\n"
                                                                "#*#*************#*#\n"
                                                                "#*###############*#\n"
                                                                "#*****************#\n"
                                                                "###################"));

    CHECK(nospaces(mat(1, 1, '$', '%')) != nospaces("%"));//20-should print $ 
}
