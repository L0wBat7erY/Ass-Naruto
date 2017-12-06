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
    string loai = eList.at(0).code;
    loai[loai.length() - 1] = '\0';
    for(int i=0; i<loai.length(); i++)
    {
        eList.at(0).code[i] = loai[i];
    }
    eList.reverse();
    event.close();
}
