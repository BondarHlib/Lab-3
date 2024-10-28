#include "Exhibit.h"

string Exhibit::GetName()
{
    return name;
}
int Exhibit::GetYear()
{
    return year;
}

void Exhibit::Print() {
    cout << name << ' ' << year << endl;
}

void Picture::Print()  {
    cout << left << setw(10) << name
        << right << setw(6) << year
        << " square:" << setw(10) << square << endl;
}


string Picture::GetType()  {
    return "p";
}

int Picture::GetFeature()  {
    return square;
}


void Statue:: Print()  
{
    cout << left << setw(10) << name
        << right << setw(6) << year
        << " weight:" << setw(10) << mass << endl;
}

string Statue::GetType()  {
    return "s";
}

int Statue:: GetFeature() {
    return mass;
}