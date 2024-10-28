#include "Museum.h"

void Museum::AddExhibit(Exhibit* new_exhibit)
{
    arr.push_back(new_exhibit);
}

bool Museum::ChooseExhibts()
{
    cout << "Choose the numbers of the elements you are interested in(write them down one by one, when you have enough, type '0')" << endl;

    int index = 0, number, blag = 0, flag = 0;
    vector<int> arr_numbers;

    do
    {
        cin >> number;
        if (number == 0)
        {
            break;

        }
        if (number > arr.size() || number < 1)
        {
            cout << "You have selected an exhibit number that does not exist." << endl;
            return false;
        }
        arr_numbers.push_back(number);
        index++;
    } while (true);



    if (index != 0)
    {


        Exhibit* max = arr[arr_numbers[0] - 1], * min = arr[arr_numbers[0] - 1];

        for (int i = 1; i < index; i++)
        {
            if (max->GetYear() < arr[arr_numbers[i] - 1]->GetYear())
            {
                max = arr[arr_numbers[i] - 1];
            }
        }

        for (int i = 1; i < index; i++)
        {
            if (min->GetYear() > arr[arr_numbers[i] - 1]->GetYear())
            {
                min = arr[arr_numbers[i] - 1];
            }
        }

        cout << "newest:";
        max->Print();
        cout << "oldest:";
        min->Print();

        Exhibit* large= nullptr, * light= nullptr;
        vector<Exhibit*> pict_arr;
        for (int i = 0; i < index; i++) {
            if (arr[arr_numbers[i] - 1]->GetType() == "p") {
                pict_arr.push_back(arr[arr_numbers[i] - 1]);
            }
        }

        if (pict_arr.size() != 0) {
            large = pict_arr[0];
            for (int i = 1; i < pict_arr.size(); i++) {
                if (large->GetFeature() < pict_arr[i]->GetFeature())
                {

                    large = pict_arr[i];
                }
            }
        }

            vector<Exhibit*> stat_arr;
            for (int i = 0; i < index; i++) {
                if (arr[arr_numbers[i] - 1]->GetType() == "s") {
                    stat_arr.push_back(arr[arr_numbers[i] - 1]);
                }
            }

            if (stat_arr.size() != 0) {
                light = stat_arr[0];
                for (int i = 1; i < stat_arr.size(); i++) {
                    if (light->GetFeature() > stat_arr[i]->GetFeature())
                    {

                        light = stat_arr[i];
                    }
                }
            }
                


        if ((pict_arr.size() != 0) && (stat_arr.size() != 0)) {
            cout << "The biggest picture:";
            large->Print();
            cout << "The lightest statue:";
            light->Print();
        }
        else if (pict_arr.size() == 0) {
            cout << "Not one picture is selected" << endl;

            cout << "The lightest statue:";
            light->Print();
        }
        else {
            cout << "The biggest picture:";
            large->Print();
            cout << "Not one statue is selected" << endl;
        }


        return true;
    }
    else
    {
        cout << "You have not selected any exhibits." << endl;
        return false;
    }
}

bool Museum::LoadExhibtsFromFile(const string& file_name)
{
    ifstream file(file_name);
    if (!file) {
        cerr << "Can't open file: " << file_name << endl;
        return false;
    }

    string name, b, ty;
    int year, d;

    while (getline(file, ty) && getline(file, name) && file >> year && file >> d)
    {
        file.ignore();
        if (ty == "p")
        {
            AddExhibit(new Picture(name, year, d));
        }
        else if (ty == "s") {
            AddExhibit(new Statue(name, year, d));
        }
    }

    file.close();
    return true;
}

void Museum::PrintMuseum(COORD cc) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, ATTR1);
    SetConsoleCursorPosition(h, cc);
    int i = 0;
    for (auto& mus : arr) {
        cout << i + 1 << ". ";
        mus->Print();
        i++;
    }
}

int  Museum::Size_of()
{
    return arr.size();
}

Museum:: ~Museum() {

    for (Exhibit* exhibit : arr) {
        delete exhibit;
    }
}