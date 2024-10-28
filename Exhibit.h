#pragma once
#include <vector>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define ATTR1 240
#define ATTR2 15
extern string m[];
extern string m1[];

using namespace std;


class Exhibit
{
protected:
    string name;
    int year;

public:
    Exhibit(string a, int b) : name(a), year(b) {};

    string GetName();
    int GetYear();

    virtual void Print();

    virtual string GetType() = 0;

    virtual int GetFeature() = 0;

};

class Picture : public Exhibit
{
private:
    int square;


public:
    Picture(string name, int year, int square) : Exhibit(name, year), square(square) {}
    
    void Print() override;
    
    string GetType() override;

    int GetFeature() override;

};



class Statue : public Exhibit
{
private:
    int mass;

public:
    Statue(string name, int year, int mass) : Exhibit(name, year), mass(mass) {}
    void Print()  override;

    string GetType() override;

    int GetFeature() override;

};



