#ifndef SYMPHOGEARCARD_H
#define SYMPHOGEARCARD_H
#include <string>
#include <map>
#include <fstream>

struct Card {
    std::string Name;
    std::string Element;
    std::string Rarity;
};

class SymphogearCard
{
    public:
        SymphogearCard();
        std::string GetName(unsigned CardNumber) {return List.find(CardNumber)->second.Name;}
        std::string GetElement(unsigned CardNumber) {return List.find(CardNumber)->second.Element;}
        std::string GetRarity(unsigned CardNumber) {return List.find(CardNumber)->second.Rarity;}

    private:
        std::map<unsigned, Card> List;
};

#endif // SYMPHOGEARCARD_H
