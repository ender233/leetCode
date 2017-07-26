#pragma once

#include <ratio> 
#include <chrono> 

using namespace std;
using namespace chrono;

class TimeRecord
{
    public:
        TimeRecord() : initFlag(0) {}

        // time gap
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
            lastTimeStamp = cur.time_since_epoch().count();
            cout << index << ":" << curTimeStampDiff<<" microseconds"<<endl;
        }

        // scope time gap
        ~TimeRecord() 
        {
            time_point<system_clock,microseconds> cur = time_point_cast<microseconds>(system_clock::now());
            int curTimeStampDiff = cur.time_since_epoch().count() - lastTimeStamp;

            cout << "end to clac the timestamp, curTimeStampDiff:" << curTimeStampDiff << endl;
        }

    private:
        int lastTimeStamp;
        int initFlag;
};
