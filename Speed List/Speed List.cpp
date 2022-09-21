// Speed List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <cmath>
//test
#define PI 3.141592653589793

using namespace std;

double Vx = 0;
double Vy = 0;
double W = 0;

int main()
{
    ofstream fout;
    fout.open("SpeedListW.txt");

    double stepTime = 0.1;
    double totalTime = 15; 
    double Velocity = 0.15;

    int quantityPoint = totalTime / stepTime;
    int lenght2R = quantityPoint / (PI + 1);
    int lenghtL = (PI * quantityPoint) / (PI + 1);

    double gamma;

    cout << quantityPoint << "\t" << lenght2R << "\t" << lenghtL;

/*
    for (int i = 0; i < quantityPoint; i++)
    {
        if (i <= lenght2R) {
            Vx = Velocity;
            fout << Vx << " " << Vy << " " << W << endl;
        }
        else if (i > lenght2R) {
            gamma = PI / lenghtL * (i - lenght2R);
            Vx = -Velocity * sin(gamma);
            Vy = -Velocity * cos(gamma);
            fout << Vx << " " << Vy << " " << W << endl;
        
        }
    }
    
    */

    

    for (int i = 0; i < quantityPoint; i++)
    {
        if (i < quantityPoint / 2) {
            W = Velocity;
        }
        else if (i >= quantityPoint / 2) {
            W = -Velocity;
        }
        fout << Vx << " " << Vy << " " << W << endl;
    }


    fout.close();
    
 }
