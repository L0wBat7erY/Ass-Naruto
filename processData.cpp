/*
 * =========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */
#include "eventLib.h"
#include "dbLib.h"


void initNinjaList(NinjaInfo_t &n, void* v)
{
    
}

bool processEvent(ninjaEvent_t& event, L1List<NinjaInfo_t>& nList, void* pGData) {
    // TODO: Your code comes here

    string code = event.code;
    string str;
    str = event.code;
    if(str.length()==1)
    {
        if(code == "0")
        {
            ifstream ecode;
            ecode.open("events.txt");
            string str;
            getline(ecode, str);
            cout<<event.code<<": "<<str<<endl;
            ecode.close();
            return true;
        }
        if(code=="1")
        {
            cout<<event.code<<": "<<nList.at(0).id<<endl;
            return true;
        }
        if(code=="2")
        {
            int i=0;
            while(i<nList.getSize()) i++;
            cout<<event.code<<": "<<nList.at(i-1).id<<endl;
            return true;
        }
        if(code=="3")
        {
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            unsigned long size = nList.getSize();
            pList->insertHead(nList.at(0));
            int a=0;
            for(int i=0; i<size; i++)
            {
                if(pList->find(nList.at(i), a)==false)
                {
                    pList->insertHead(nList.at(i));
                }
            }
            
            
            cout<<event.code<<": "<<pList->getSize()<<endl;
            
            return true;
        }
        if(code=="4")
        {
            int max=atoi(nList.at(0).id);
            int i=0;
            while(i<nList.getSize())
            {
                if(max<atoi(nList.at(i).id)) max = atoi(nList.at(i).id);
                i++;
            }
            cout<<event.code<<": "<<max<<endl;
            return true;
        }
        if(code=="9")
        {
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            L1List<NinjaInfo>* pnewList = new L1List<NinjaInfo>;
            unsigned long size1 = nList.getSize();
            
            
            int a=0;
            double dmax=0, Smax=0;
            pList->insertHead(nList.at(0));
            for(int i=0; i<size1; i++)
            {
                if(pList->find(nList.at(i), a)==false)
                {
                    pList->insertHead(nList.at(i));
                }
            }
            unsigned long size2 = pList->getSize();
            int j=0;
            string foundid;
            while(j<size2)
            {
                pnewList->insertHead(pList->at(j));
                int b=0;
                for(int i=0; i<size1; i++)
                {
                    if(pnewList->find(nList.at(i), b)==true)
                        pnewList->insertHead(nList.at(i));
                }
                unsigned long size3 = pnewList->getSize();
            
                for(int i=1; i<size3; i++)
                {
                    double d = distanceEarth(pnewList->at(i).latitude, pnewList->at(i).longitude, pnewList->at(i-1).latitude, pnewList->at(i-1).longitude);
                    dmax = dmax + d;
                }
                if(Smax<=dmax)
                {
                    foundid = pnewList->at(0).id;
                    Smax = dmax;
                }
                pnewList->clean();
                j++;
            }
            cout<<event.code<<": "<<foundid<<endl;
            
            return true;
        }
        
        
    }
    if(str.length()==5)
    {
        if(str[0]=='5')
        {
            char codeid[5];
            int j = 0;
            for(int i=1; i<5; i++)
            {
                codeid[j] = str[i];
                j++;
            }
            
            codeid[j] = '\0';
            
            int i=0, dem=0;
            for(i=0; i<nList.getSize(); i++)
            {
                if(strcmp(codeid, nList.at(i).id)==0)
                {
                    dem++;
                    break;
                }
            }
            if(dem==0)
            {
                cout<<event.code<<": "<<-1;
                return false;
            }
            char des[30];
            strPrintTime(des, nList.at(i).timestamp);
            cout<<event.code<<": "<<des<<endl;
            return true;
        }
        if(str[0]=='6')
        {
            char codeid[5];
            int n = 0;
            for(int i=1; i<5; i++)
            {
                codeid[n] = str[i];
                n++;
            }
            codeid[n] = '\0';
            
            int j=0;
            unsigned long size = nList.getSize();
            L1List<NinjaInfo> newList;
            for(int i=0; i<size; i++)
            {
                
                if(strcmp(codeid, nList.at(i).id)==0)
                {
                    newList.insertHead(nList.at(i));
                    j++;
                }
            }
            if(j==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return false;
            }
            size = newList.getSize();
            int i;
            for(i=1; i<size; i++)
            {
                double d = distanceEarth(newList.at(i).latitude, newList.at(i).longitude, newList.at(i-1).latitude, newList.at(i-1).longitude);
                if(d<=0.005) break;
            }
            
            for(j=1; j<size-i-1; j++)
            {
                double d = distanceEarth(newList.at(i-1).latitude, newList.at(i-1).longitude, newList.at(i-1+j).latitude, newList.at(i-1+j).longitude);
                if(d>0.005) break;
            }
            
            char des[30];
            strPrintTime(des, newList.at(i-1+j-1).timestamp);
            cout<<event.code<<": "<<des<<endl;
            return true;
        }
        if(str[0]=='7')
        {
            char codeid[5];
            int n = 0;
            for(int i=1; i<5; i++)
            {
                codeid[n] = str[i];
                n++;
            }
            codeid[n] = '\0';
            
            int j=0;
            unsigned long size = nList.getSize()-1;
            L1List<NinjaInfo> newList;
            for(int i=0; i<size; i++)
            {
                
                if(strcmp(codeid, nList.at(i).id)==0)
                {
                    newList.insertHead(nList.at(i));
                    j++;
                }
            }
            if(j==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return false;
            }
            int i=0, dem=0;
            size = newList.getSize()-1;
            for(i=1; i<size; i++)
            {
                double d = distanceEarth(newList.at(i).latitude, newList.at(i).longitude, newList.at(i-1).latitude, newList.at(i-1).longitude);
                if(d<=0.005)
                {
                    dem++;
                    for(j=1; j<size-i; j++)
                    {
                        d = distanceEarth(newList.at(i-1).latitude, newList.at(i-1).longitude, newList.at(i-1+j).latitude, newList.at(i-1+j).longitude);
                        if(d>0.005)
                        {
                            i=i-1+j;
                            break;
                        }
                    }
                }
            }
            
            
            cout<<event.code<<": "<<dem<<endl;
            
            return true;
        }
        
        if(str[0]=='8')
        {
            char codeid[5];
            int n = 0;
            for(int i=1; i<5; i++)
            {
                codeid[n] = str[i];
                n++;
            }
            codeid[n] = '\0';
            
            int j=0;
            unsigned long size = nList.getSize()-1;
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            for(int i=0; i<size; i++)
            {
                
                if(strcmp(codeid, nList.at(i).id)==0)
                {
                    pList->insertHead(nList.at(i));
                    j++;
                }
            }
            if(j==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return false;
            }
            
            double dmax=0;
            size = pList->getSize();
            for(int i=1; i<size; i++)
            {
                double d = distanceEarth(pList->at(i).latitude, pList->at(i).longitude, pList->at(i-1).latitude, pList->at(i-1).longitude);
                dmax = dmax + d;
            }
            
            cout<<event.code<<": "<<dmax<<endl;
            
            return true;
        }
        
        
        
    }
    if(code=="10")
    {
        cout<<event.code<<": "<<endl;
        return true;
    }
    
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}

