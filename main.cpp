/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: paulmelki
 *
 * Created on May 4, 2018, 8:57 PM
 */

#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include "Graph.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    string line;
    int lineCount = 0;

    int numberOfVertices = 0;

    vector<string> namesOfCities;

    ifstream myFile("cities.txt");

    if (myFile.is_open()) {

        while (getline(myFile, line)) {

            if (!isdigit(line[0])) {
                numberOfVertices++;
                namesOfCities.push_back(line);
            }

            lineCount++;
        }

        myFile.close();
    } else cout << "Unable to open file!" << endl;

    
    Graph * airports = new Graph(numberOfVertices);
 
    airports->addVertices(namesOfCities);
    
    int cityNumber = 0;

    ifstream f("cities.txt");

    if (f.is_open()) {
    
        while (getline(f, line)) {

            if (isdigit(line[0])) {

                int num;
                string s = line.substr(0, 1);
                istringstream iss(s);
                iss >> num;
                string weightString = line.substr(2);
                stringstream converter(weightString);
                double weight;
                converter >> weight;

                airports->addEdge(cityNumber - 1, num - 1, weight);

            } else {
                cityNumber++;
            }

            lineCount++;
        }

        f.close();
    }


    airports->display();
    
    airports->findShortestPath(3, 8);

    return 0;
}

