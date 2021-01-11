// © copyright 2020 Ricky Prophete. All Rights Reserved.
// Author: Ricky Prophete
// Date: 4/9/2020
// Contact: ricky.prophete@live.lagcc.cuny.edu
// Description: A menu-driven program to play, manipulate music files, and save music files.
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Note
{
    int frequency;
    int duration;
};

using MPX = vector<Note>; //Making a new type MPX that consists of a vector of notes
MPX Data = { {500, 1000}, {800, 1000}, {500, 1000}, {1000, 500} };

enum Options : const char ////Used in switch statement in execute()
{
    openOption = 'O', playOption = 'P', shift_F_Option = 'F',
    shift_D_Option = 'D', saveNewFileOption = 'S', aboutOption = 'A',
    quitOption = 'Q', dirOption = 'L'
};

void openFile(MPX& Data);
void playSongFile(MPX& Data);
void changeSongFileFrequency(MPX& Data);
void changeSongFileDuration(MPX& Data);
void save(MPX& Data);
void quit();
void bye();
void wait();
void aboutUs();
void welcome(MPX& Data);
char displayMenu();
bool isChoiceValid(char c);
void execute(char& cmd);

static int M = 0; ////invoking clear variables

int main()
{
    if (M == 0) welcome(Data); ////Hello
    char cmd;
    do
    {
        system("cls");
        cmd = displayMenu();//// returns command & displays menu
        execute(cmd);////input: char command output: depends on switch function in execute()

    } while (cmd != quitOption); ////loop until user quits
    return 0;
}

void openFile(MPX& Data) //input: address of container magnitude variable output: no output
{
    Data.clear();
    Data.shrink_to_fit();
    M = 0;
    ifstream fin; ////object to get data from file
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    fin.open(filename);
    if (!fin.is_open())
    {
        cerr << "The file could not be opened" << endl;
        return;
    }
    cout << "...File is open" << endl;
    for (int i = 0; !fin.eof(); i++)
    {
        Note note;
        fin >> note.frequency >> note.duration;
        Data.push_back(note);
        M++;
    }
    fin.close();
}

void playSongFile(MPX& Data)
{
    if (M == 0)
    {
        cerr << "USER MUST OPEN SONG\n";
        Sleep(1000);
        return;
    }
    else if (M > 0)
    {
        cout << "...Playing" << endl;
        for (auto x : Data)
        {
            Beep(x.frequency, x.duration);
        }
    }
    else
    {
        return;
    }
}

void changeSongFileFrequency(MPX& Data)
{
    if (M == 0)
    {
        cerr << "USER MUST OPEN SONG\n";
        Sleep(1000);
        return;
    }
    else if (M > 0)
    {
        double scale, lowest = 0, highest = 20000;
        do
        {
            system("cls");
            cout << "Enter magnitude of frequency change" << endl;
            cout << "Enter value between 0 & 20000" << endl;
            cin >> scale;
            for (auto& x : Data)
            {
                x.frequency *= scale;
            }
        } while (scale < lowest || scale > highest);
        cout << "...Changing Frequency" << endl;
    }
    else
    {
        return;
    }
}
void changeSongFileDuration(MPX& Data)
{
    if (M == 0)
    {
        cerr << "USER MUST OPEN SONG\n";
        Sleep(1000);
        return;
    }
    else if (M > 0)
    {
        double scale, lowest = 0, highest = 200;
        do
        {
            system("cls");
            cout << "Enter magnitude of duration change" << endl;
            cout << "Enter value between 0 & 200" << endl;
            cin >> scale;
            for (auto& x : Data)
            {
                x.duration *= scale;
            }
        } while (scale < lowest || scale > highest);
        cout << "...Changing Frequency" << endl;
    }
    else
    {
        return;
    }
}

void save(MPX& Data)
{
    if (M == 0)
    {
        cerr << "USER MUST OPEN SONG\n";
        Sleep(1000);
        return;
    }
    else if (M > 0)
    {
        string newFile;
        cout << "Enter a new file name: ";
        cin >> newFile;
        
        ofstream fout; ////object to put data into a file
        fout.open(newFile);
        if (!fout.is_open())
        {
            cerr << "File could not be saved" << endl;
            return;
        }
        for (auto& x : Data)
        {
            fout << x.frequency << '\t' << x.duration << endl; ////output data to a file
            ////cout << Data[i].frequency<< '\t' << Data[i].duration<<endl; //////check output
        }
        cerr << "...File saved" << endl;
        fout.close();
    }

}

void quit()
{
    char q;
    do
    {
        system("cls");
        cerr << "\nAre you sure? Data you entered may not be saved.\n"
            << "|Enter 'y' to exit|    |'n' to cancel|    |'s' to save & quit|" << endl;
        cin >> q;
        if (q == 'y')
        {
            bye();
        }
        else if (q == 'n')
        {
            main();
        }
        else if (q == 's')
        {
            if (M == 0) ////Check if a file was opened. Exit program if not
            {
                bye();
            }
            save(Data);
            bye();
        }
        else
        {
            continue;
        }
    } while (q != 'y' || q != 'n' || q != 's');

}
void bye()
{
    cerr << "Thank you for using MPX Editor. Goodbye" << endl;
    Data.clear();
    Data.shrink_to_fit();
    exit(0);
}

void wait()
{
    Sleep(1000);
    cerr << "PRESS ANY KEY TO CONTINUE";
    while (!_kbhit()); ////Wait for user to start
    _getch();
}

void aboutUs()
{
    system("cls");
    cerr << "© copyright 2020 Ricky Prophete. All Rights Reserved.\n"
        << "Author: Ricky Prophete\n"
        << "Date: 4/9/2020\n"
        << "Contact: ricky.prophete@live.lagcc.cuny.edu\n"
        << "Description: A menu-driven program to play and manipulate music from a file.\n";
    wait();
}

void welcome(MPX& Data)
{
    system("cls");
    cerr << "Welcome to Music Editor MPX";
    for (auto x : Data)
    {
        Beep(x.frequency, x.duration);
    }
    Sleep(1000);
    system("cls");
    wait();
}

char displayMenu()
{
    char choice;
    do
    {
        system("cls");
        cerr << "Enter a command: \n"
            << "####################################\n"
            << "# L...List songs                   #\n"
            << "# O...Open a music file            #\n"
            << "# P...Play music                   #\n"
            << "# F...frequency change             #\n"
            << "# D...duration change              #\n"
            << "# S...Save song                    #\n"
            << "# A...Learn about Prophete Studios #\n"
            << "# Q...Quit music editor            #\n"
            << "####################################\n"
            << "Entry: ";
        cin >> choice;
    } while (!isChoiceValid(choice));////Check if choice is valid input before continuing

    return choice;
}

bool isChoiceValid(char choice)
{
    for (auto op : { 'O','P' ,'F' ,'D' , 'S' ,'A','Q', 'L' })
    {
        if (op == choice)
        {
            return true;
        }
    }
    return false;
}


void execute(char& cmd)
{
    switch (cmd)
    {
    case openOption:
        openFile(Data);
        break;

    case playOption:
        playSongFile(Data);
        break;

    case shift_F_Option:
        changeSongFileFrequency(Data);
        break;

    case shift_D_Option:
        changeSongFileDuration(Data);
        break;

    case aboutOption:
        aboutUs();
        break;

    case saveNewFileOption:
        save(Data);
        break;

    case quitOption:
        quit();
        break;

    case dirOption:
        system("cls");
        system("dir *.mpx");
        wait();
        break;
    default:
        cerr << "That was not quite right. Try again";
    }
    Sleep(1000);
}




