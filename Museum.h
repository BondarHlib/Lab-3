#pragma once
#include "Exhibit.h"

class Museum
{
private:
    vector<Exhibit*> arr;

public:
    void AddExhibit(Exhibit* new_exhibit);

    bool ChooseExhibts();

    bool LoadExhibtsFromFile(const string& file_name);

    void PrintMuseum(COORD cc);

    int Size_of();

    Exhibit& operator[](int index)
    {
        return *arr[index];
    }

	~Museum();
};

