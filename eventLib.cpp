/*
 * =========================================================================================
 * Name        : eventLib.cpp
 * Author      : Duc Dung Nguyen, Nguyen Hoang Minh
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
 *               This library contains functions used for event management
 * =========================================================================================
 */

#include "eventLib.h"


/// NOTE: each event will be separated by spaces, or endline character
void loadEvents(char* fName, L1List<ninjaEvent_t> &eList) {
	//TODO
    ninjaEvent_t eventList;
    ifstream event;
    event.open(fName);
    while(!event.eof())
    {
        event>>eventList.code;
        eList.insertHead(eventList);
    }
    eList.reverse();
    event.close();
}
