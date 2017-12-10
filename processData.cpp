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
            cout<<event.code<<":";
            L1Item<ninjaEvent>* p;
            p = (L1Item<ninjaEvent>*) pGData;
            
            while(p!=NULL)
            {
                cout<<" "<<p->data.code;
                p=p->pNext;
            }
            cout<<endl;

            return true;
        }
        if(code=="1")
        {
            cout<<event.code<<": "<<nList.getHead()->data.id<<endl;
            return true;
        }
        if(code=="2")
        {
            L1Item<NinjaInfo>* p=nList.getHead();
            while(p->pNext!=NULL) p=p->pNext;
            cout<<event.code<<": "<<p->data.id<<endl;
            return true;
        }
        if(code=="3")
        {
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            
            L1Item<NinjaInfo>* p = nList.getHead();
            pList->insertHead(p->data);
            
            while(p!=NULL)
            {
                if(pList->find(p->data)==false) pList->insertHead(p->data);
                p=p->pNext;
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
        if(code=="5") return false;
        if(code=="6") return false;
        if(code=="7") return false;
        if(code=="8") return false;
        if(code=="9")
        {
            L1List<NinjaInfo>* pdiffList = new L1List<NinjaInfo>;
            L1List<NinjaInfo>* psameList = new L1List<NinjaInfo>;
            L1Item<NinjaInfo>* pdiff = nList.getHead();
            L1Item<NinjaInfo>* p = NULL;
            string foundid;
            
            double dmax=0;
            double Smax=0;
            pdiffList->insertHead(pdiff->data);
            for(pdiff = nList.getHead(); pdiff!=NULL; pdiff=pdiff->pNext)
            {
                if(pdiffList->find(pdiff->data)==false)
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
            psameList->clean();
            pdiffList->clean();
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
            int dem=0, n=0;
            double d=0, s=0;
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
            if(dem==1)
            {
                char des[30];
                strPrintTime(des, pList->getHead()->data.timestamp);
                cout<<event.code<<": "<<des<<endl;
                return true;
            }
            if(dem==0)
            {
                cout<<event.code<<": "<<-1<<endl;
                return true;
            }
            pList->reverse();
            L1Item<NinjaInfo>* pre = pList->getHead();
            p=pList->getHead()->pNext;
            L1Item<NinjaInfo>* pcur=pre;
            d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
            int socdlai=0;
            if(d<=0.005)
            {
                while(p!=NULL)
                {
                    s = distanceEarth(pcur->data.latitude, pcur->data.longitude, p->data.latitude, p->data.longitude);
                    if(s>0.005)
                    {
                        socdlai++;
                        pre=p;
                        break;
                    }
                    if(d==s) n++;
                    p=p->pNext;
                }
            }
            
            char des[30];
            strPrintTime(des, pre->data.timestamp);
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
            pList->reverse();
            
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
            if(pcur!=NULL)
            {
                char des[30];
                strPrintTime(des, pcur->data.timestamp);
                cout<<event.code<<": "<<des<<endl;
            }
            else cout<<event.code<<": "<<"Non-stop"<<endl;
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
            pList->clean();
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
            pList->clean();
            return true;
        }
        
        
        
    }
    if(code=="10")
    {
        L1List<NinjaInfo>* pdiffList = new L1List<NinjaInfo>;
        L1List<NinjaInfo>* psameList = new L1List<NinjaInfo>;
        L1Item<NinjaInfo>* pdiff = nList.getHead();
        L1Item<NinjaInfo>* p = NULL;
        string foundid1;
        
        time_t movetime = 0;
        time_t maxmovetime = 0;
        
        pdiffList->insertHead(pdiff->data);
        
        for(pdiff = nList.getHead(); pdiff!=NULL; pdiff=pdiff->pNext)
        {
            if(pdiffList->find(pdiff->data)==false) pdiffList->insertHead(pdiff->data);
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
            L1Item<NinjaInfo>* pcur = NULL;
            L1Item<NinjaInfo>* pfol = NULL;
            while(p!=NULL)
            {
                double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                
                movetime = movetime + (p->data.timestamp - pre->data.timestamp);
                if(d<=0.005)
                {
                    movetime = movetime - (p->data.timestamp - pre->data.timestamp);
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
                    movetime = movetime + (p->data.timestamp - pre->data.timestamp);
                    if(p==NULL) break;
                }
                
                pre = pre->pNext;
                p=p->pNext;
            }
            if(maxmovetime<=movetime)
            {
                maxmovetime = movetime;
                foundid1 = psameList->getHead()->data.id;
                
            }
            
            movetime=0;
            psameList->clean();
            pdiff=pdiff->pNext;
        }
        
        cout<<event.code<<": "<<foundid1<<endl;
        pdiffList->clean();
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
            strcode[j] = '\0';
            
            L1List<NinjaInfo>* pList = new L1List<NinjaInfo>;
            
            L1Item<NinjaInfo>* p = nList.getHead();
            pList->insertHead(p->data);
            for(p = nList.getHead(); p!=NULL; p=p->pNext)
            {
                if(pList->find(p->data)==false)
                    pList->insertHead(p->data);
            }
            pList->reverse();
            p = pList->getHead()->pNext;
            L1Item<NinjaInfo>* pre = pList->getHead();
            while(p!=NULL)
            {
                if(strcmp(strcode, p->data.id)==0) break;
                pre=pre->pNext;
                p=p->pNext;
            }
            cout<<event.code<<": "<<pre->data.id<<endl;
            p = nList.getHead();
            
            while(p!=NULL)
            {
                if(strcmp(p->data.id, pre->data.id)==0) nList.remove(pre->data);
                
                p=p->pNext;
            }
            return true;
        }
        else
        {
            cout<<event.code<<": "<<-1<<endl;
            return true;
        }
    }
    if(code=="11") return false;
    if(code=="12")
    {
        L1List<NinjaInfo>* pdiffList = new L1List<NinjaInfo>;
        L1List<NinjaInfo>* psameList = new L1List<NinjaInfo>;
        L1Item<NinjaInfo>* pdiff = nList.getHead();
        L1Item<NinjaInfo>* p = NULL;
        string foundid;
        
        time_t stoptime = 0;
        time_t maxstoptime = 0;
        pdiffList->insertHead(pdiff->data);
        for(pdiff = nList.getHead(); pdiff!=NULL; pdiff=pdiff->pNext)
        {
            if(pdiffList->find(pdiff->data)==false)
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
        pdiffList->clean();
        return true;
    }
    
    
    
    if(code=="13")
    {
        
        return false;
    }
    
    if(code=="14")
    {
        cout<<event.code<<":";
        L1List<NinjaInfo>* pdiffList = new L1List<NinjaInfo>;
        L1List<NinjaInfo>* psameList = new L1List<NinjaInfo>;
        L1List<NinjaInfo>* pmoveList = new L1List<NinjaInfo>;
        L1Item<NinjaInfo>* pdiff = nList.getHead();
        L1Item<NinjaInfo>* p = NULL;
        int khongcoid=0;
        int flag1=0;
        int flag2=0;
        pdiffList->insertHead(pdiff->data);
        for(pdiff = nList.getHead(); pdiff!=NULL; pdiff=pdiff->pNext)
        {
            if(pdiffList->find(pdiff->data)==false)
                pdiffList->insertHead(pdiff->data);
        }
        pdiffList->reverse();
        pdiff = pdiffList->getHead();
        while(pdiff!=NULL)
        {
            p=nList.getHead();
            while(p!=NULL)
            {
                if(strcmp(p->data.id, pdiff->data.id)==0) psameList->insertHead(p->data);
                p=p->pNext;
            }
            psameList->reverse();
            L1Item<NinjaInfo>* pre = psameList->getHead();
            p=psameList->getHead()->pNext;
            L1Item<NinjaInfo>* pcur = NULL;
            L1Item<NinjaInfo>* pfol = NULL;
            L1Item<NinjaInfo>* pnew;
            while(p!=NULL)
            {
                
                double d=distanceEarth(pre->data.latitude, pre->data.longitude, p->data.latitude, p->data.longitude);
                
                pmoveList->insertHead(pre->data);
                if(d<=0.005)
                {
                    flag1=0;
                    pcur = pre;
                    pre=pre->pNext;
                    pfol = pcur;
                    while(pre->pNext!=NULL)
                    {
                        d=distanceEarth(pcur->data.latitude, pcur->data.longitude, pre->data.latitude, pre->data.longitude);
                        
                        if(d>0.005) {flag1=1; break;}
                        
                        pfol = pfol->pNext;
                        pre = pre->pNext;
                    }
                    pre = pfol;
                    
                    p = pre->pNext;
                    if(p==NULL) { flag2=1; break;}
                }
                
                pre = pre->pNext;
                p=p->pNext;
                
            }
            pnew=psameList->getHead();
            while(pnew->pNext!=NULL){
                if(pre->data.timestamp==pnew->pNext->data.timestamp) break;
                pnew=pnew->pNext;
            }
            if(distanceEarth(pnew->data.latitude, pnew->data.longitude, pre->data.latitude, pre->data.longitude)>0.005) pmoveList->insertHead(pre->data);
            flag2=0; flag1=0;
            psameList->clean();
            pmoveList->reverse();
            if(pmoveList->getSize()>1)
            {
                L1Item<NinjaInfo>* premove = pmoveList->getHead();
                L1Item<NinjaInfo>* pmove = pmoveList->getHead()->pNext;
                int dem = 0;
                double s=0;
                while(premove!=NULL)
                {
                    while(pmove!=NULL)
                    {
                        s = distanceEarth(pmove->data.latitude, pmove->data.longitude, premove->data.latitude, premove->data.longitude);
                        //if(strcmp(pmoveList->getHead()->data.id, "8840")==0) cout<<" "<<s<<"   ";
                        if(s<=0.005)
                        {
                            dem=1;
                            break;
                        }
                        pmove=pmove->pNext;
                    }
                    if(dem==1)
                    {
                        cout<<" "<<pmoveList->getHead()->data.id;
                        khongcoid++;
                        break;
                    }
                    premove=premove->pNext;
                    pmove=premove->pNext;
                    if(pmove==NULL) break;
                }
                //if(strcmp(pmoveList->getHead()->data.id, "8840")==0) cout<<" "<<distanceEarth(37.75703, -122.3901, 37.75704, -122.38986)<<premove->data.latitude;
            }
            
            
            pmoveList->clean();
            pdiff=pdiff->pNext;
        }
        if(khongcoid==0) cout<<" "<<-1;
        cout<<endl;
        pdiffList->clean();
        return true;
    }
    
    else
    {
        if(str[0]=='1' && str[1]=='3')
        {
            //cout<<event.code<<": "<<-1<<endl;
            return true;
        }
        
    }
    if(str.length()==4)
    {
        cout<<event.code<<": "<<-1<<endl;
        return true;
    }
    if(str.length()==3)
    {
        cout<<event.code<<": "<<-1<<endl;
        return true;
    }
    
    /// NOTE: The output of the event will be printed on one line
    /// end by the endline character.
    return false;
}

