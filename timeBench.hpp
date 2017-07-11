#pragma once

#include <ratio> 
#include <chrono> 

using namespace std;
using namespace chrono;

class TimeRecord
{
    public:
        TimeRecord(){}

        void printTimeDiff(std::string index) {
            if(!initFlag)  {
                cout << index <<":";
                cout << "begin to clac the first stamptime" <<endl;
                time_point<system_clock,microseconds> cur = time_point_cast<microseconds>(system_clock::now());
                lastTimeStamp = cur.time_since_epoch().count();
                initFlag = 1;
                return;
            }   

            time_point<system_clock,microseconds> cur = time_point_cast<microseconds>(system_clock::now());
            int curTimeStampDiff = cur.time_since_epoch().count() - lastTimeStamp;
            cout << index << ":" << curTimeStampDiff<<" microseconds"<<endl;
        }

    private:
        int lastTimeStamp;
        int initFlag;
};

