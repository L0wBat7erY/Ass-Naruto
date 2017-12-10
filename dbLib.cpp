/*
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen, Nguyen Hoang Minh
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : library for Assignment 1 - Data structures and Algorithms - Fall 2017
 *               This file implements functions used for database management
 * =========================================================================================
 */

#include "dbLib.h"

#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

using namespace std;

void    strPrintTime(char* des, time_t& t) {
    tm *pTime = localtime(&t);
    strftime(des, 26, "%Y-%m-%d %H:%M:%S", pTime);
}

void loadNinjaDB(char* fName, L1List<NinjaInfo_t> &db) {
	// TODO: write code to load information from file into db
    NinjaInfo_t ninja;
    ifstream data;
    data.open(fName);
    string str;
    getline(data, str);
    int sodong = 0;
    while(!data.eof())
    {
        if(str=="") return;
        
        getline(data, str);
        stringstream ss;
        ss<<str;
        char comma;
        int i;
        for(i=0; i<6; i++)
        {
            ss>>comma;
            if(comma == ',') break;
        }
        int date, mon, year, h, min, sec;
        ss>>mon>>comma>>date>>comma>>year;
        ss>>h>>comma>>min>>comma>>sec>>comma;
        char mangchuaidgoc[ID_MAX_LENGTH];
        for(i=0; i<10; i++)
        {
            ss>>comma;
            if(comma == ',') break;
            mangchuaidgoc[i]=comma;
        }
        mangchuaidgoc[i] = '\0';
        if(i==1)
        {
            ninja.id[0] = '0';
            ninja.id[1] = '0';
            ninja.id[2] = '0';
            ninja.id[3] = mangchuaidgoc[0];
            ninja.id[4] = '\0';
        }
        if(i==2)
        {
            ninja.id[0] = '0';
            ninja.id[1] = '0';
            ninja.id[2] = mangchuaidgoc[0];
            ninja.id[3] = mangchuaidgoc[1];
            ninja.id[4] = '\0';
        }
        if(i==3)
        {
            ninja.id[0] = '0';
            ninja.id[1] = mangchuaidgoc[0];
            ninja.id[2] = mangchuaidgoc[1];
            ninja.id[3] = mangchuaidgoc[2];
            ninja.id[4] = '\0';
        }
        if(i>=4 && i<=ID_MAX_LENGTH) strcpy(ninja.id, mangchuaidgoc);
        ss>>ninja.longitude>>comma>>ninja.latitude;
        
        struct tm t;
        t.tm_year = year - 1900;
        t.tm_mon = mon - 1;
        t.tm_mday = date;
        t.tm_hour = h;
        t.tm_min = min;
        t.tm_sec = sec;
        t.tm_isdst = -1;
        
        ninja.timestamp = mktime(&t);
        db.insertHead(ninja);
        
        sodong++;
    }
    
    db.reverse();
    data.close();
}

bool parseNinjaInfo(char* pBuf, NinjaInfo_t& nInfo) {
    // TODO: write code to parse information from a string buffer, ignore if you don't use it
    return true;
}


void process(L1List<ninjaEvent_t>& eventList, L1List<NinjaInfo_t>& bList) {
    void*       pGData = NULL;
    initNinjaGlobalData(&pGData);
    
    pGData = eventList.getHead();
    
    while (!eventList.isEmpty()) {
        if(!processEvent(eventList[0], bList, pGData))
            cout << eventList[0].code << " is an invalid event\n";
        eventList.removeHead();
    }
    
    releaseNinjaGlobalData(pGData);
}


bool initNinjaGlobalData(void** pGData) {
    /// TODO: You should define this function if you would like to use some extra data
    /// the data should be allocated and pass the address into pGData
    
    
    
    
    
    return true;
}

void releaseNinjaGlobalData(void* pGData) {
    /// TODO: You should define this function if you allocated extra data at initialization stage
    /// The data pointed by pGData should be released
}


void printNinjaInfo(NinjaInfo_t& b) {
    printf("%s: (%0.5f, %0.5f), %s\n", b.id, b.longitude, b.latitude, ctime(&b.timestamp));
}

/// This function converts decimal degrees to radians
double deg2rad(double deg) {
    return (deg * pi / 180);
}

///  This function converts radians to decimal degrees
double rad2deg(double rad) {
    return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = deg2rad(lat1d);
    lon1r = deg2rad(lon1d);
    lat2r = deg2rad(lat2d);
    lon2r = deg2rad(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}
