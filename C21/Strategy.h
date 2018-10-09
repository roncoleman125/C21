/*
Copyright (c) Ron Coleman
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once
#include "Hand.h"

/*!
  \enum Strategy
  \brief Plays player can make.
*/
typedef enum {
	NO_PLAY = 0,        /**< Default play */
	STAY = 'S', 
	HIT = 'H', 
	DOUBLE_DOWN = 'D', 
	SPLIT = 'P' 
} Play;

/*! \def Total number of rules in a strategy. */
#define NUMBER_RULES (10*43)

/*! \def Section 1 index in jump (lookaside) table */
#define SECTION1 0

/*! \def Section 2 index in jump (lookaside) table */
#define SECTION2 1

/*! \def Section 2 index in jump (lookaside) table */
#define SECTION3 2

/*! \def Section 2 index in jump (lookaside) table */
#define SECTION4 3

// Macros to make table formatting read better
#define S STAY
#define H HIT
#define D DOUBLE_DOWN
#define P SPLIT
#define X NO_PLAY

/*!
  \struct Strategy
  \brief  Defines a strategy.
*/
typedef struct {
	float pl;
	Play rules[NUMBER_RULES];
} Strategy;


/*!
  \brief Basic strategy constructor
  Makes a basic strategy from Instructional Services (1983, 2000)
*/
Strategy BasicStrategy_();

/*!
  \brief Basic strategy constructor
  Makes a default, "no play" strategy
*/
Strategy Strategy_();

/*!
  \brief Does section IV of strategy
  \param hand Hand pointer
  \param upcard Dealer upcard pointer
  \param strategy Strategy pointer
*/
Play doSection4(Hand* hand, Card* upcard, Strategy* strategy);

/*!
  \brief Does section III of strategy
  \param hand Hand pointer
  \param upcard Dealer upcard pointer
  \param strategy Strategy pointer
*/
Play doSection3(Hand* hand, Card* upcard, Strategy* strategy);

/*!
  \brief Does section II of strategy
  \param hand Hand pointer
  \param upcard Dealer upcard pointer
  \param strategy Strategy pointer
*/
Play doSection2(Hand* hand, Card* upcard, Strategy* strategy);

/*!
\brief Does section I of strategy
\param hand Hand pointer
\param upcard Dealer upcard pointer
\param strategy Strategy pointer
*/
Play doSection1(Hand* hand, Card* upcard, Strategy* strategy);

/*!
  \brief Gets the captured play frequencies for a number of games.
  \return Pointer to array same size as strategy.
  \see Strategy
*/
int* getPlays();