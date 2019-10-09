#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss (s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main()
{
    string EventName, Wellfares, XPMemoria, XPSymphogear, Gold, Mats, DateEnd, CurrencyName, TotalCost;
    vector<string> VWellfares;
    vector<string> VMats;
    ifstream Input ("Event.txt");

    getline(Input, EventName);
    getline(Input, Wellfares);
    getline(Input, XPMemoria);
    getline(Input, XPSymphogear);
    getline(Input, Gold);
    getline(Input, Mats);
    getline(Input, DateEnd);
    getline(Input, CurrencyName);
    getline(Input, TotalCost);

    if (Wellfares != "0") VWellfares = split(Wellfares, ';');
    VMats = split(Mats, ';');

    ofstream Output ("Event - " + EventName + ".txt");

    Output << "__**Quest Efficiency**__" << endl
           << "```" << endl
           << endl
           << "```" << endl
           << "-----------------------------------------" << endl
           << "__**Notable Shop Item**__" << endl
           << "```" << endl;

    for (unsigned i (0); i < VWellfares.size(); i += 3) {
        Output << VWellfares[i] << " ";
        unsigned Thousands = (VWellfares[i + 1].size() - 1) / 3;
        for (unsigned j (1); j <= Thousands; j++)
            VWellfares[i+1].insert((VWellfares[i+1].size()) / 2, " ");
        Output << VWellfares[i + 1] << " (" << VWellfares[i + 2] << ")" << endl;
    }

    Output << "XP Memoria (" << XPMemoria << ")" << endl
           << "XP Symphogear (" << XPSymphogear << ")" << endl
           << "Gold (" << Gold << ")" << endl;

    for (string mat : VMats)
        Output << mat << " Awakening Materials" << endl;

    Output << "```" << endl
           << "-----------------------------------------" << endl
           << "__**Special Quests**__" << endl
           << "```" << endl
           << endl
           << "```" << endl
           << "-----------------------------------------" << endl
           << "End Date : " << DateEnd << endl
           << "Shop Total : ";
    unsigned Thousands = (TotalCost.size() - 1) / 3;
    for (unsigned j (1); j <= Thousands; j++)
        TotalCost.insert((TotalCost.size()) / 2, " ");
    Output << TotalCost << " " << CurrencyName;


    return 0;
}
