#include "Menu.h"
string m[] = { "Start", "Help", "About", "Exit" };
string m1[] = { "Add", "Choose", "Exit" };

bool Start() {

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cs;
    SetConsoleTextAttribute(hStdOut, ATTR1);
    system("cls");
    cs.X = 1;
    cs.Y = 1;
    int f1 = 1, k = 0, n = 3, len = 9;
    char button = 10;
    Museum arr;
    if (!arr.LoadExhibtsFromFile("MyFile.txt"))
    {
        _getch();
        return false;
    }


    draw2(k, n, len, arr);

    while (f1) {
        if (_kbhit()) {
            button = _getch();
            switch (button) {
            case 27:
                f1 = 0;
                break;
                system("cls");
                draw2(k, n, len, arr);
                break;
            case 13: {
                switch (k) {
                case 0:
                    Add(arr);
                    break;
                case 1:
                    Choose_inv(arr);
                    break;
                case 2:
                    f1 = 0;
                    break;
                };
                system("cls");
                draw2(k, n, len, arr);
                break;
            }
            case 77:
                if (k == n - 1) k = 0;
                else k++;
                draw2(k, n, len, arr);
                break;
            case 75:
                if (k == 0) k = n - 1;
                else k--;
                draw2(k, n, len, arr);
                break;
            }
        }
    }

    ofstream fout;
    fout.open("MyFile.txt");
    if (!fout.is_open())
    {
        cout << "Error of open" << endl;
        _getch();
    }
    else
    {
        for (int i = 0; i < arr.Size_of(); ++i) {
            string lll = arr[i].GetType();
            fout << lll << endl;
            fout << arr[i].GetName() << endl;
            fout << arr[i].GetYear() << endl;
            fout << arr[i].GetFeature() << endl;
        }

    }
    fout.close();
    return true;

}

int Add(Museum& mus) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cs;
    SetConsoleTextAttribute(hStdOut, ATTR1);
    system("cls");
    cs.X = 1;
    cs.Y = 1;
    string a, g, r;
    int b, k;
    char i;
    cout << "Write the type of the new exhibit(picture or statue):" << endl;

    cin >> r;
    if ((r != "statue") && (r != "picture")) {
        cout << "Wrong type!" << endl;
        _getch();
        return 0;
    }

    cout << "Write the name of the new exhibit:" << endl;

    cin >> i;
    getline(cin, g);
    cout << "Write the year of the new exhibit:" << endl;
    cin >> b;

    if (i != '\0')
    {
        a = i + g;
    }
    else {
        a = g;
    }

    if (r == "picture")
    {
        cout << "Write the square of the new exhibit:" << endl;
        cin >> k;
        mus.AddExhibit(new Picture(a, b, k));
    }
    else if (r == "statue") {
        cout << "Write the weight of the new exhibit:" << endl;
        cin >> k;
        mus.AddExhibit(new Statue(a, b, k));
    }

    return 1;


}
void Choose_inv(Museum& mus) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cs;
    SetConsoleTextAttribute(hStdOut, ATTR1);
    system("cls");
    cs.X = 1;
    cs.Y = 1;
    mus.ChooseExhibts();
    _getch();


}
void Help() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cs;
    SetConsoleTextAttribute(hStdOut, ATTR1);
    system("cls");
    cs.X = 1;
    cs.Y = 1;
    cout << "You can use this program for .. bla bla";


    _getch();


}
void About() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD cs;
    SetConsoleTextAttribute(hStdOut, ATTR1);
    system("cls");
    cs.X = 1;
    cs.Y = 1;
    cout << "The program was created by ...";


    _getch();
};




void draw(int k, int n, int len) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, ATTR1);
    system("cls");
    COORD cursorPos, cc;

    char c;
    int i, j;
    CONSOLE_SCREEN_BUFFER_INFO inf;
    GetConsoleScreenBufferInfo(hStdOut, &inf);
    cc.X = ((inf.srWindow.Right - 2) / 2);
    cc.Y = 4;

    cursorPos.X = 1;
    cursorPos.Y = 1;
    c = 457;
    SetConsoleCursorPosition(hStdOut, cursorPos); cout << c;
    for (i = 2; i < (inf.srWindow.Right - 1); i++) {
        cursorPos.X = i; SetConsoleCursorPosition(hStdOut, cursorPos); c = 461; cout << c;
    }
    cursorPos.X = (inf.srWindow.Right - 1); SetConsoleCursorPosition(hStdOut, cursorPos); c = 443; cout << c;
    for (j = 2; j < (inf.srWindow.Bottom - 1); j++) {
        cursorPos.Y = j; SetConsoleCursorPosition(hStdOut, cursorPos); c = 442; cout << c;
    }


    cursorPos.Y = (inf.srWindow.Bottom - 1); SetConsoleCursorPosition(hStdOut, cursorPos); c = 444; cout << c;


    for (i = (inf.srWindow.Right - 2); i > 1; i--) {
        cursorPos.X = i; SetConsoleCursorPosition(hStdOut, cursorPos); c = 461; cout << c;
    }
    cursorPos.X = 1; SetConsoleCursorPosition(hStdOut, cursorPos); c = 456; cout << c;


    for (j = (inf.srWindow.Bottom - 2); j > 1; j--) {
        cursorPos.Y = j; SetConsoleCursorPosition(hStdOut, cursorPos); c = 442; cout << c;
    }
    cursorPos.X = ((inf.srWindow.Right - 3) / 2);
    cursorPos.Y = 2;
    SetConsoleCursorPosition(hStdOut, cursorPos);
    cout << "Museum";
    cursorPos.X = ((inf.srWindow.Right - 2) / 2);
    cursorPos.Y = 4;
    for (int l = 0; l < n; l++) {
        cursorPos.Y = cc.Y + l * len;
        SetConsoleCursorPosition(hStdOut, cursorPos);
        cout << m[l];
    }
    cursorPos.Y = cc.Y + k * len;
    SetConsoleTextAttribute(hStdOut, ATTR2);
    SetConsoleCursorPosition(hStdOut, cursorPos);
    cout << m[k];


}


void draw2(int k, int n, int len, Museum& mus)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, ATTR1);
    system("cls");
    COORD cursorPos, cc;

    CONSOLE_SCREEN_BUFFER_INFO inf;
    GetConsoleScreenBufferInfo(h, &inf);
    cc.X = 1;
    cc.Y = 2;

    cursorPos.X = 0;
    cursorPos.Y = 4;
    mus.PrintMuseum(cursorPos);

    cursorPos.X = 1;
    cursorPos.Y = 1;

    for (int l = 0; l < n; l++) {
        cursorPos.X = cc.X + l * len;
        SetConsoleCursorPosition(h, cursorPos);
        cout << m1[l];
    }
    cursorPos.X = cc.X + k * len;
    cursorPos.Y = 1;
    SetConsoleTextAttribute(h, ATTR2);
    SetConsoleCursorPosition(h, cursorPos);
    cout << m1[k];
    cin.clear();

}

void Menu_1()
{
    int f1 = 1, k = 0, n = 4, len = 5;
    char button = 10;

    draw(0, n, len);
    while (f1) {
        if (_kbhit()) {
            button = _getch();
            switch (button) {
            case 27:
                f1 = 0;
                break;
            case 13: {
                switch (k) {
                case 0:
                    Start();
                    break;
                case 1:
                    Help();
                    break;
                case 2:
                    About();
                    break;
                case 3:
                    f1 = 0;


                };
                system("cls");
                draw(k, n, len);
                break;
            }
            case 80:
                if (k == n - 1) k = 0;
                else k++;
                draw(k, n, len);
                break;
            case 72:
                if (k == 0) k = n - 1;
                else k--;
                draw(k, n, len);
                break;
            }
        }
    }
}