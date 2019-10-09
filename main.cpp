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

void Event () {
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

    ofstream Output ("Gacha - " + GachaName + ".txt");
    Output << "__**Cost**__" << endl
           << "```" << endl
           << endl
           << "```" << endl
           << "__**Steps**__" << endl
           << "```" << endl;

    for (unsigned i (0); i < Steps.size(); ++i) {
        Convert(Steps[i]);
        Output << i + 1 << " : " << Steps[i] << endl;
    }

    Output <<"```" << endl
          << "__**Rate-up**__" << endl
          << "```" << endl;

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

    Output <<"```" << endl
           << "End Date : " << EndDate << " CEST" << endl;
}

int main()
{
    Event();
    Gacha();
    return 0;
}
/*
```
__**Rate-up**__
```
Symphogear :
    - Demon's Angry Shout
    - BLOODY†CURSE
Memoria :
    - Dangerous P.E. Storage Room
    - Visible Catastrophe
```
End date : 2019/10/16 6:59 CEST
*/
