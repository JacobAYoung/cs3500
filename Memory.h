#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

class Memory 
{
    private:
    //vars
    string allocationAlgorithm = "";
    int memorySize = 0;
    vector<int> trace;
    vector<int> traceMap;
    int lastTimeStep = 0;
    int timeStepNumber = 0;
    int tracePosition = 0;

    public:
    //Default constructor
    Memory(){}

    void setTimeStepNumber(int timeStep) {
        timeStepNumber = timeStep;
    }

    void setAllocationAlgorithm(vector<string> fileContents) {
        allocationAlgorithm = fileContents.front();
    }

    void setMemorySize(vector<string> fileContents) {
        istringstream iss (fileContents[1]);
        iss >> memorySize;
    }

    void setTrace(vector<string> fileContents, int start) {
        for (int i = start; i < fileContents.size(); i++) {
            int num = atoi(fileContents.at(i).c_str());
            trace.push_back(num);
        }
    }

    void setTraceMap(vector<int> traceContent) {
        for (int i = 0; i < traceContent.size(); i++) {
            traceMap[i] = traceContent[i];
        }
    }

    void setLastTimeStep(int timeStep) {
        lastTimeStep = timeStep;
    }

    void setTracePosition(int tracePos) {
        tracePosition = tracePos;
    }

    int getTracePosition() {
        return tracePosition;
    }

    int getLastTimeStep() {
        return lastTimeStep;
    }

    vector<int> getTraceMap() {
        return traceMap;
    }

    void printTraceMap(vector<int> traceMapData) {
        cout << "|";
        for (int i = 0; i < traceMapData.size(); i++) {
          cout << " " << traceMapData[i] << " |";
        }
        cout << endl;
    }

    int getTimeStep() {
        return timeStepNumber;
    }

    vector<int> getTrace() {
        return trace;
    }

    string getAllocationAlgorithm() {
        return allocationAlgorithm;
    }

    int getMemorySize() {
        return memorySize;
    }
    void fillVector(int memSize) {
        for (int i = 0; i < memSize; i++) {
            traceMap.push_back(0);
        }
    }

    vector<string> loadFile(string fileName)
    {
        vector<string> fileContents;
        ifstream file;
        file.open(fileName);
        if (!file.is_open()) {
            cout << "File could not be found." << endl;
            return fileContents;
        }

        string word;
        while (file >> word)
        {
            fileContents.push_back(word);
        }
        return fileContents;
    }

    int cleanTraceMap(vector<int> traceMapData, int timeStep) {
        int found = 0;
        for (int i = 0; i < traceMapData.size(); i++) {
            if (traceMapData[i] == timeStep) {
                traceMapData[i] = 0;
                found++;
            }
        }
        setTraceMap(traceMapData);
        return found;
    }

    void firstFitAlgorithm(vector<int> traceData, vector<int> traceMapData, int memSize, int timeStep) {
        int totalProcessMemSize = 0;
        int timeStepCounter = 0;
        int lastCounter = 0;
        int positionCounter = getTracePosition();

        //vars getting data from trace
        int processBeginTime = 0;
        int processMemSize = 0;
        int processEndTime = 0;

        int tempMemSize = 0;
        int totalTime = 0;

        int consecutiveCounter = 0;
        int firstPosition = -1;
        int secondPosition = -1;

        cout << "Previous Time Step: " << getLastTimeStep() << endl;
        if (timeStep == 0) {
            printTraceMap(traceMapData);
            return;
        }

        while (timeStepCounter < timeStep) {
            if (positionCounter >= traceData.size()) {
                setTimeStepNumber(getLastTimeStep());
                cout << "Current Time Step: " << getTimeStep() << endl;
                cout << "There is not enough trace data to continue." << endl;
                printTraceMap(traceMapData);
                return;
            }
            //Clean out the old processes at the current timestep
            int cleaned = cleanTraceMap(traceMapData, timeStepCounter+1);
            totalProcessMemSize = totalProcessMemSize - cleaned;

            if (positionCounter > lastCounter) {
                lastCounter+=3;
                timeStepCounter++;
                continue;
            }

            //Set default vars
            traceMapData = getTraceMap();
            firstPosition = -1;
            secondPosition = -1;
            consecutiveCounter = 0;

            //Get the data from the traceData
            processBeginTime = traceData[positionCounter];
            processMemSize = traceData[positionCounter+1];
            processEndTime = traceData[positionCounter+2];
            tempMemSize = processMemSize + totalProcessMemSize;

            //Check if the memory size is greater then the allocated memory size
            if (tempMemSize > memSize) {
                //Trash the proceess and continue on
                timeStepCounter++;
                positionCounter+=3;
                lastCounter+=3;
                continue;
            } else {
                totalProcessMemSize = tempMemSize;
                totalTime = processBeginTime + processEndTime;
            }

            //Find the ideal locations for the trace map
            for (int i = 0; i < memSize; i++) {
                if (processMemSize == consecutiveCounter) {
                    break;
                }
                if (traceMapData[i] == 0) {
                    if (firstPosition == -1) {
                        firstPosition = i;
                    }
                    secondPosition = i;
                    consecutiveCounter++;
                } else if (firstPosition != -1 && traceMapData[i] != 0) {
                    firstPosition = -1;
                    secondPosition = -1;
                    consecutiveCounter = 0;
                }
            }
            if (firstPosition != -1 && secondPosition != -1 && consecutiveCounter == processMemSize) {
                for (int i = firstPosition; i <= secondPosition; i++) {
                    traceMapData[i] = totalTime;
                }
                setTraceMap(traceMapData);
            }

            timeStepCounter++;
            positionCounter+=3;
            lastCounter+=3;
        }
        cout << "Current Time Step: " << timeStep << endl;
        setTracePosition(positionCounter);
        setLastTimeStep(timeStep);
        printTraceMap(traceMapData);   
    }

    void bestFitAlgorithm(vector<int> traceData, vector<int> traceMapData, int memSize, int timeStep) {
        int totalProcessMemSize = 0;
        int timeStepCounter = 0;
        int lastCounter = 0;
        int positionCounter = getTracePosition();

        //vars getting data from trace
        int processBeginTime = 0;
        int processMemSize = 0;
        int processEndTime = 0;

        int tempMemSize = 0;
        int totalTime = 0;

        int consecutiveCounter = 0;
        int firstPosition = -1;
        int secondPosition = -1;

        cout << "Previous Time Step: " << getLastTimeStep() << endl;
        if (timeStep == 0) {
            printTraceMap(traceMapData);
            return;
        }

        while (timeStepCounter < timeStep) {
            if (positionCounter >= traceData.size()) {
                setTimeStepNumber(getLastTimeStep());
                cout << "Current Time Step: " << getTimeStep() << endl;
                cout << "There is not enough trace data to continue." << endl;
                printTraceMap(traceMapData);
                return;
            }
            //Clean out the old processes at the current timestep
            int cleaned = cleanTraceMap(traceMapData, timeStepCounter+1);
            totalProcessMemSize = totalProcessMemSize - cleaned;

            if (positionCounter > lastCounter) {
                lastCounter+=3;
                timeStepCounter++;
                continue;
            }

            //Set default vars
            traceMapData = getTraceMap();
            firstPosition = -1;
            secondPosition = -1;
            consecutiveCounter = 0;

            //Get the data from the traceData
            processBeginTime = traceData[positionCounter];
            processMemSize = traceData[positionCounter+1];
            processEndTime = traceData[positionCounter+2];
            tempMemSize = processMemSize + totalProcessMemSize;

            //Check if the memory size is greater then the allocated memory size
            if (tempMemSize > memSize) {
                //Trash the proceess and continue on
                timeStepCounter++;
                positionCounter+=3;
                lastCounter+=3;
                continue;
            } else {
                totalProcessMemSize = tempMemSize;
                totalTime = processBeginTime + processEndTime;
            }
            //Find the ideal locations for the trace map
            for (int i = 0; i < memSize; i++) {
                if (processMemSize == consecutiveCounter) {
                    break;
                }
                if (traceMapData[i] == 0) {
                    if (firstPosition == -1) {
                        firstPosition = i;
                    }
                    secondPosition = i;
                    consecutiveCounter++;
                } else if (firstPosition != -1 && traceMapData[i] != 0) {
                    firstPosition = -1;
                    secondPosition = -1;
                    consecutiveCounter = 0;
                }
            }
            if (firstPosition != -1 && secondPosition != -1 && consecutiveCounter == processMemSize) {
                for (int i = firstPosition; i <= secondPosition; i++) {
                    traceMapData[i] = totalTime;
                }
                setTraceMap(traceMapData);
            }

            timeStepCounter++;
            positionCounter+=3;
            lastCounter+=3;
        }
        cout << "Current Time Step: " << timeStep << endl;
        setTracePosition(positionCounter);
        setLastTimeStep(timeStep);
        printTraceMap(traceMapData);   
    }


    
};

#endif