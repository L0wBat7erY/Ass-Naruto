/*
 * =========================================================================================
 * Name        : processData.cpp
 * Description : student code for Assignment 1 - Data structures and Algorithms - Fall 2017
 * =========================================================================================
 */
#include "eventLib.h"
#include "dbLib.h"


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
            cout<<event.code<<": "<<nList.at(i-2).id<<endl;
            return true;
        }
        if(code=="3")
        {
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            int a=0;
            L1Item<NinjaInfo>* p = nList.getHead();
            pList->insertHead(p->data);
            for(p = nList.getHead(); p!=NULL; p=p->pNext)
            {
                if(pList->find(p->data, a)==false)
                    pList->insertHead(p->data);
            }
            cout<<event.code<<": "<<pList->getSize()<<endl;
            pList->clean();
            return true;
        }
        if(code=="4")
        {
            L1Item<NinjaInfo>* p = nList.getHead();
            char max[ID_MAX_LENGTH];
            strcpy(max, p->data.id);
            
            p = p->pNext;
            while(p != NULL){
                if(strcmp(max, p->data.id) < 0){
                    strcpy(max, p->data.id);
                }
                p = p->pNext;
            }
            cout<<event.code<<": "<<max<<endl;
            return true;
            
        }
        if(code=="9")
        {
            L1List<NinjaInfo>* pdiffList = new L1List<NinjaInfo>;
            L1List<NinjaInfo>* psameList = new L1List<NinjaInfo>;
            L1Item<NinjaInfo>* pdiff = nList.getHead();
            L1Item<NinjaInfo>* p = NULL;
            string foundid;
            int a=0;
            double dmax=0;
            double Smax=0;
            pdiffList->insertHead(pdiff->data);
            for(pdiff = nList.getHead(); pdiff!=NULL; pdiff=pdiff->pNext)
            {
                if(pdiffList->find(pdiff->data, a)==false)
                    pdiffList->insertHead(pdiff->data);
            }
            pdiff = pdiffList->getHead();
            while(pdiff!=NULL)
            {
                for(p=nList.getHead(); p!=NULL; p=p->pNext)
                {
                    if(strcmp(p->data.id, pdiff->data.id)==0) psameList->insertHead(p->data);
                }
                psameList->reverse();
                L1Item<NinjaInfo>* pre = psameList->getHead();
                p=psameList->getHead()->pNext;
                while(p!=NULL)
                {
                    double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                    dmax+=d;
                    pre = pre->pNext;
                    p=p->pNext;
                }
                psameList->clean();
                if(Smax<=dmax)
                {
                    Smax = dmax;
                    foundid = pdiff->data.id;
                }
                dmax=0;
                pdiff=pdiff->pNext;
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
            int dem=0;
            L1Item<NinjaInfo>* p = nList.getHead();
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            for(p = nList.getHead(); p->pNext!=NULL; p=p->pNext)
            {
                if(strcmp(codeid, p->data.id)==0)
                {
                    dem++;
                    pList->insertHead(p->data);
                }
            }
            if(dem==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return true;
            }
            pList->reverse();
            p=pList->getHead()->pNext;
            while(p!=NULL)
            {
                double d=distanceEarth(pList->getHead()->data.latitude, pList->getHead()->data.longitude, p->data.latitude, p->data.longitude);
                if(d>0.005){
                    break;
                }
                p=p->pNext;
            }
            char des[30];
            strPrintTime(des, p->data.timestamp);
            cout<<event.code<<": "<<des<<endl;
            pList->clean();
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
            int dem=0;
            L1Item<NinjaInfo>* p = nList.getHead();
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            for(p = nList.getHead(); p->pNext!=NULL; p=p->pNext)
            {
                if(strcmp(codeid, p->data.id)==0)
                {
                    dem++;
                    pList->insertHead(p->data);
                }
            }
            if(dem==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return true;
            }
            p=pList->getHead()->pNext;
            L1Item<NinjaInfo>* pre = pList->getHead();
            while(p!=NULL)
            {
                double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                if(d<0.005){
                    break;
                }
                pre = pre->pNext;
                p=p->pNext;
            }
            char des[30];
            strPrintTime(des, p->data.timestamp);
            
            cout<<event.code<<": "<<des<<endl;
            pList->clean();
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
            
            int dem=0;
            L1Item<NinjaInfo>* p = nList.getHead();
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            for(p = nList.getHead(); p->pNext!=NULL; p=p->pNext)
            {
                if(strcmp(codeid, p->data.id)==0)
                {
                    dem++;
                    pList->insertHead(p->data);
                }
            }
            if(dem==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return true;
            }
            pList->reverse();
            int j=0;
            p = pList->getHead()->pNext;
            L1Item<NinjaInfo>* pre = pList->getHead();
            L1Item<NinjaInfo>* pcur = NULL;
            L1Item<NinjaInfo>* pfol = NULL;
            while(p!=NULL)
            {
                double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                if(d<=0.005)
                {
                    pcur = pre;
                    j++;
                    pre=pre->pNext;
                    pfol = pcur;
                    while(pre->pNext!=NULL)
                    {
                        d=distanceEarth(pcur->data.latitude, pcur->data.longitude, pre->data.latitude, pre->data.longitude);
                        
                        if(d>0.005) break;
                        pfol = pfol->pNext;
                        pre = pre->pNext;
                    }
                    pre = pfol;
                    p = pre->pNext;
                    if(p==NULL) break;
                }
                pre = pre->pNext;
                p=p->pNext;
            }
            
            
            cout<<event.code<<": "<<j<<endl;
            
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
            
            int dem=0;
            L1Item<NinjaInfo>* p = nList.getHead();
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            for(p = nList.getHead(); p->pNext!=NULL; p=p->pNext)
            {
                if(strcmp(codeid, p->data.id)==0)
                {
                    dem++;
                    pList->insertHead(p->data);
                }
            }
            if(dem==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return true;
            }
            p = pList->getHead()->pNext;
            L1Item<NinjaInfo>* pre = pList->getHead();
            double max = 0;
            while(p!=NULL)
            {
                double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                max+=d;
                pre = pre->pNext;
                p=p->pNext;
            }
            
            cout<<event.code<<": "<<max<<endl;
            
            return true;
        }
        
        
        
    }
    if(code=="10")
    {
        L1List<NinjaInfo>* pdiffList = new L1List<NinjaInfo>;
        L1List<NinjaInfo>* psameList = new L1List<NinjaInfo>;
        L1Item<NinjaInfo>* pdiff = nList.getHead();
        L1Item<NinjaInfo>* p = NULL;
        string foundid;
        int a=0;
        time_t movetime = 0;
        time_t maxmovetime = 0;
        pdiffList->insertHead(pdiff->data);
        for(pdiff = nList.getHead(); pdiff!=NULL; pdiff=pdiff->pNext)
        {
            if(pdiffList->find(pdiff->data, a)==false)
                pdiffList->insertHead(pdiff->data);
        }
        pdiffList->reverse();
        pdiff = pdiffList->getHead();
        while(pdiff!=NULL)
        {
            for(p=nList.getHead(); p!=NULL; p=p->pNext)
            {
                if(strcmp(p->data.id, pdiff->data.id)==0) psameList->insertHead(p->data);
            }
            psameList->reverse();
            L1Item<NinjaInfo>* pre = psameList->getHead();
            p=psameList->getHead()->pNext;
            L1Item<NinjaInfo>* pcur = NULL;
            L1Item<NinjaInfo>* pfol = NULL;
            while(p!=NULL)
            {
                double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                
                
                if(d<=0.005)
                {
                    pcur = pre;
                    pre=pre->pNext;
                    pfol = pcur;
                    while(pre->pNext!=NULL)
                    {
                        d=distanceEarth(pcur->data.latitude, pcur->data.longitude, pre->data.latitude, pre->data.longitude);
                        
                        if(d>0.005) break;
                        pfol = pfol->pNext;
                        pre = pre->pNext;
                    }
                    pre = pfol;
                    p = pre->pNext;
                    if(p==NULL) break;
                }
                movetime += p->data.timestamp - pre->data.timestamp;
                pre = pre->pNext;
                p=p->pNext;
            }
            psameList->clean();
            if(maxmovetime<=movetime)
            {
                maxmovetime = movetime;
                foundid = pdiff->data.id;
            }
            movetime=0;
            pdiff=pdiff->pNext;
        }
        cout<<event.code<<": "<<foundid<<endl;
        return true;
    }
    
    if(str.length()==6)
    {
        if(str[0]=='1' && str[1]=='1')
        {
            char strcode[5];
            int j = 0;
            for(int i=2; i<6; i++)
            {
                strcode[j++] = str[i];
            }
            NinjaInfo nin;
            int a=0;
            strcpy(nin.id, strcode);
            nList.find(nin, a);
            cout<<event.code<<": "<<nList.at(a-1).id<<endl;
            return true;
        }
        else return false;
    }
    
    if(code=="12")
    {
        L1List<NinjaInfo>* pdiffList = new L1List<NinjaInfo>;
        L1List<NinjaInfo>* psameList = new L1List<NinjaInfo>;
        L1Item<NinjaInfo>* pdiff = nList.getHead();
        L1Item<NinjaInfo>* p = NULL;
        string foundid;
        int a=0;
        time_t stoptime = 0;
        time_t maxstoptime = 0;
        pdiffList->insertHead(pdiff->data);
        for(pdiff = nList.getHead(); pdiff!=NULL; pdiff=pdiff->pNext)
        {
            if(pdiffList->find(pdiff->data, a)==false)
                pdiffList->insertHead(pdiff->data);
        }
        pdiffList->reverse();
        pdiff = pdiffList->getHead();
        while(pdiff!=NULL)
        {
            for(p=nList.getHead(); p!=NULL; p=p->pNext)
            {
                if(strcmp(p->data.id, pdiff->data.id)==0) psameList->insertHead(p->data);
            }
            psameList->reverse();
            L1Item<NinjaInfo>* pre = psameList->getHead();
            p=psameList->getHead()->pNext;
            L1Item<NinjaInfo>* pcur = NULL;
            L1Item<NinjaInfo>* pfol = NULL;
            while(p!=NULL)
            {
                double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                
                
                if(d<=0.005)
                {
                    pcur = pre;
                    pre=pre->pNext;
                    pfol = pcur;
                    while(pre->pNext!=NULL)
                    {
                        d=distanceEarth(pcur->data.latitude, pcur->data.longitude, pre->data.latitude, pre->data.longitude);
                        
                        if(d>0.005) break;
                        stoptime += pre->data.timestamp - pfol->data.timestamp;
                        pfol = pfol->pNext;
                        pre = pre->pNext;
                    }
                    pre = pfol;
                    p = pre->pNext;
                    if(p==NULL) break;
                }
                
                pre = pre->pNext;
                p=p->pNext;
            }
            psameList->clean();
            if(maxstoptime<=stoptime)
            {
                maxstoptime = stoptime;
                foundid = pdiff->data.id;
            }
            stoptime=0;
            pdiff=pdiff->pNext;
        }
        
        cout<<event.code<<": "<<foundid<<endl;
    }
    
    
    
    if(code=="13")
    {
        
        return false;
    }
    
    if(code=="14")
    {
        cout<<event.code<<": "<<-1<<endl;
        return true;
    }
    
    else
    {
        if(str[0]=='1' && str[1]=='3')
        {
            cout<<event.code<<": "<<-1<<endl;
            return true;
        }
        else return false;
    }
    
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return true;
}

