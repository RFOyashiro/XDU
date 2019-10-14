#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "SymphogearCard.h"
#include "MemoriaCard.h"

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
    vector<string> WellfaresRari;
    ifstream Input ("Event.txt");

    getline(Input, EventName);
    getline(Input, line);

    while (line != "0"){
        Wellfares.push_back(line);
        getline(Input, line);
        WellfaresRari.push_back(line);
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

    for (unsigned i (0); i < Wellfares.size(); ++i) {
        Output << Wellfares[i] << "   ";
        for (unsigned j (0); j < stoi(WellfaresRari[i]); ++j)
            Output << "★";
        Output << endl;
    }

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

void Convert (string & str, vector<string> RateUp) {
    if (str == "40") str = "4* Memoria";
    else if (str == "41") str = "4* Symphogear";
    else if (str == "50") str = "5* Memoria";
    else if (str == "51") str = "5* Symphogear";
    else if (str == "52") str = "5* Symphogear Rate-Up";
    else str = RateUp[stoi(str) - 1];
}

void Gacha() {
    SymphogearCard SGCardlist;
    MemoriaCard MECardlist;
    string GachaName, line, EndDate;
    vector<string> Steps;
    vector<string> RateUpSG;
    vector<string> RateUpME;
    vector<string> RateUpMERari;
    ifstream Input ("Gacha.txt");

    getline(Input, GachaName);
    getline(Input, line);

    while (line != "0") {
        Steps.push_back(line);
        getline(Input, line);
    }

    getline(Input, line);

    while (line != "0") {
        RateUpSG.push_back(line);
        getline(Input, line);
    }

    getline(Input, line);

    while (line != "0") {
        RateUpME.push_back(line);
        getline(Input, line);
    }

    getline(Input, EndDate);

    ofstream Output ("Gacha/" + GachaName + ".txt");
    Output << "__**Cost**__" << endl
           << "```" << endl
           << "-" << endl
           << "```" << endl
           << "__**Steps**__" << endl
           << "```" << endl;

    for (unsigned i (0); i < Steps.size(); ++i) {
        Convert(Steps[i], RateUpSG);
        if (i + 1 < 10 && Steps.size() >= 10)
            Output << setw(2) << i + 1 << " : " << Steps[i] << endl;
        else
            Output << i + 1 << " : " << Steps[i] << endl;
    }

    Output <<"```" << endl
          << "__**Rate-up**__" << endl;

    if (RateUpSG.size() != 0) {
        Output << "Symphogear :" << endl;

        for (unsigned i (0); i < RateUpSG.size(); ++i) {
            Output << "    - " << " :" << SGCardlist.GetElement(stoi(RateUpSG[i])) << ":  "
                   << SGCardlist.GetName(stoi(RateUpSG[i])) << "   ";
            for (unsigned j (0); j < stoi(SGCardlist.GetRarity(stoi(RateUpSG[i]))); ++j)
                Output << "★";
            Output << endl;
        }
    }

    if(RateUpME.size() != 0) {
        Output <<"Memoria :" << endl;

        for (unsigned i (0); i < RateUpME.size(); ++i) {
            Output << "    - " << MECardlist.GetName(stoi(RateUpME[i])) << "   ";
            for (unsigned j (0); j < stoi(MECardlist.GetRarity(stoi(RateUpME[i]))); ++j)
                Output << "★";
            Output << endl;
        }
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

/*ToDo : event & gacha
card
element
rarity
card
element
rarity
0
*/
int main()
{
    Event();
    Gacha();
    Symphogear();
    return 0;
}
