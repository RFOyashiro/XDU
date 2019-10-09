#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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

void Event () {
    string EventName, line, XPMemoria, XPSymphogear, Gold, Mats, DateEnd, CurrencyName, TotalCost;
    vector<string> VMats;
    vector<string> Wellfares;
    ifstream Input ("Event.txt");

    getline(Input, EventName);
    getline(Input, line);

    while (line != "0"){
        Wellfares.push_back(line);
        getline(Input, line);
    }

    getline(Input, XPMemoria);
    getline(Input, XPSymphogear);
    getline(Input, Gold);
    getline(Input, Mats);
    getline(Input, DateEnd);
    getline(Input, CurrencyName);
    getline(Input, TotalCost);

    VMats = split(Mats, ';');

    ofstream Output ("Event/" + EventName + ".txt");

    Output << "__**Quest Efficiency**__" << endl
           << endl
           << "__**Notable Shop Item**__" << endl;

    for (unsigned i (0); i < Wellfares.size(); ++i)
        Output << Wellfares[i] << endl;

    Output << endl << XPMemoria << " XP Memoria" << endl
           << XPSymphogear << " XP Symphogear" << endl
           << Gold << " Gold" << endl << endl;

    for (string mat : VMats)
        Output << ":" << mat << ":" << " Awakening Materials" << endl;

    Output << endl << "__**Special Quests**__" << endl
           << endl
           << "End Date : " << DateEnd << endl
           << "Shop Total : ";
    unsigned Thousands = (TotalCost.size() - 1) / 3;
    for (unsigned j (1); j <= Thousands; j++)
        TotalCost.insert((TotalCost.size()) / 2, " ");
    Output << TotalCost << " " << CurrencyName;
}

void Convert (string & str) {
    if (str == "4") str = "4* Memoria";
    if (str == "5") str = "5* Memoria";
    if (str == "4s") str = "4* Symphogear";
    if (str == "5s") str = "5* Symphogear";
    if (str == "5r") str = "5* Symphogear Rate-Up";
}

void Gacha() {
    string GachaName, Step, RUS, RUM, EndDate;
    vector<string> Steps;
    vector<string> RateUpSG;
    vector<string> RateUpME;
    ifstream Input ("Gacha.txt");

    getline(Input, GachaName);
    getline(Input, Step);
    getline(Input, RUS);
    getline(Input, RUM);
    getline(Input, EndDate);

    Steps = split(Step, ';');
    RateUpSG = split(RUS, ';');
    RateUpME = split(RUM, ';');

    ofstream Output ("Gacha/" + GachaName + ".txt");
    Output << "__**Cost**__" << endl
           << "```" << endl
           << "-" << endl
           << "```" << endl
           << "__**Steps**__" << endl
           << "```" << endl;

    for (unsigned i (0); i < Steps.size(); ++i) {
        Convert(Steps[i]);
        if (i + 1 < 10 && Steps.size() >= 10)
            Output << setw(2) << i + 1 << " : " << Steps[i] << endl;
        else
            Output << i + 1 << " : " << Steps[i] << endl;
    }

    Output <<"```" << endl
          << "__**Rate-up**__" << endl;

    if (RUS != "0") {
        Output << "Symphogear :" << endl;

        for (unsigned i (0); i < RateUpSG.size(); ++i)
            Output << "    - " << RateUpSG[i] << endl;
    }

    if(RUM != "0") {
        Output <<"Memoria :" << endl;

        for (unsigned i (0); i < RateUpME.size(); ++i)
            Output << "    - " << RateUpME[i] << endl;
    }

    Output << endl
           << "End Date : " << EndDate << " CEST" << endl;
}

void Symphogear() {
    string Name, Rarity, Character, Cost, Element, Type, LS, line, CD1, CD2;
    vector <string> PS;
    vector <string> S1;
    vector <string> S2;
    ifstream Input ("Symphogear.txt");

    getline(Input, Name);
    getline(Input, Rarity);
    getline(Input, Character);
    getline(Input, Cost);
    getline(Input, Element);
    getline(Input, Type);
    getline(Input, LS);
    getline(Input, line);

    while (line != "0"){
        PS.push_back(line);
        getline(Input, line);
    }

    getline(Input, CD1);
    getline(Input, line);

    while (line != "0"){
        S1.push_back(line);
        getline(Input, line);
    }

    getline(Input, CD2);
    getline(Input, line);

    while (line != "0"){
        S2.push_back(line);
        getline(Input, line);
    }

    ofstream Output ("Symphogear/" + Name + ".txt");

    Output << Character << " :" << Element << ": : " << Name << " ";

    for (unsigned i (0); i < stoi(Rarity); ++i)
        Output << "★";

    Output << " " << Cost << " (" << Type << ")" << endl << endl
           << "Leader Skill : " << LS << endl << endl
           << "Passve Skill : " << endl;
    for (unsigned i (0); i < PS.size(); ++i)
        Output << "         - " << PS[i] << endl;

    Output << endl << "Skill 1 : (CD " << CD1 << ")" << endl;
    for (unsigned i (0); i < S1.size(); ++i)
        Output << "         - " << S1[i] << endl;

    Output << endl << "Skill 2 : (CD " << CD2 << ")" << endl;
    for (unsigned i (0); i < S2.size(); ++i)
        Output << "         - " << S2[i] << endl;
}

int main()
{
    Event();
    Gacha();
    Symphogear();
    return 0;
}
