#include "functions.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

#define PI 3.141592653589793

using namespace std;

double Vx = 0;
double Vy = 0;
double W = 0;

void writeLinearSpeed(string pathOut) {
    ofstream fout;
    fout.open(pathOut);

    double stepTime = 0.1;
    double totalTime = 15;
    double Velocity = 0.15;

    int quantityPoint = totalTime / stepTime;
    int lenght2R = quantityPoint / (PI + 1);
    int lenghtL = (PI * quantityPoint) / (PI + 1);

    double gamma;


        for (int i = 0; i < quantityPoint; i++)
        {
            if (i <= lenght2R) {
                Vx = Velocity;
                fout << Vx << " " << Vy << endl;
            }
            else if (i > lenght2R) {
                gamma = PI / lenghtL * (i - lenght2R);
                Vx = -Velocity * sin(gamma);
                Vy = -Velocity * cos(gamma);
                fout << Vx << " " << Vy << endl;

            }
        }

    



    //for (int i = 0; i < quantityPoint; i++)
    //{
    //    if (i < quantityPoint / 2) {
    //        W = Velocity;
    //    }
    //    else if (i >= quantityPoint / 2) {
    //        W = -Velocity;
    //    }
    //    fout << Vx << " " << Vy << " " << W << endl;
    //}


    fout.close();


}


void columnParser(string pathIn, string pathOut) {

    string t = "t";
    string Vx_o = "Vx_o";
    string Vy_o = "Vy_o";
    string dpsi = "dpsi";
    string x0 = "x0";
    string y0 = "y0";

    vector <int> columnNumber;

    int i = 0;

    string str;

    ofstream fout;
    fout.open(pathOut);

    ifstream fin;
    fin.open(pathIn);

    if (!fin.is_open()) {
        cout << "File open error" << endl;
    }
    else {
        cout << "File is open" << endl;

        while (!fin.eof())
        {
            str = "";
            getline(fin, str);
            i++;
            string wordData = "";
            int wordCount = 0;
            bool flag = false;
            if (i == 1) {
                for (auto c : str) {
                    
                    if (c != ' ' && c != '\t' && c != ',') {
                        flag = false;
                        wordData.push_back(c);
                    }
                    else if ((c == ' ' || c == '\t' || c == ',') && !flag) {
                        flag = true;
                        wordCount++;
                        if (wordData == x0 || wordData == y0) {
                            columnNumber.push_back(wordCount);
                            cout << wordData << "\t";
                        }
                        wordData.clear();
                    }

                }
                if (wordCount == 15) {
                    cout << endl;
                    for (int c = 0; c < columnNumber.size(); c++) {
                        cout << columnNumber[c] << "\t";
                    }
                    cout << endl;
                }
                
            }

            if (i != 1) {
                for (auto c : str) {

                    if (c != ' ' && c != '\t' && c != ',') {
                        flag = false;
                        wordData.push_back(c);
                    }
                    else if ((c == ' ' || c == '\t' || c == ',') && !flag) {
                        flag = true;
                        wordCount++;
                        bool found = find(columnNumber.begin(), columnNumber.end(), wordCount - 1) != columnNumber.end();
                        if (found) {
                            fout << wordData << "\t";
                        }
                        wordData.clear();

                        if (wordCount == 15) {
                            fout << endl;
                        }
                    }
                
                }
            
            }


        }

    }
    fin.close();
    fout.close();


}