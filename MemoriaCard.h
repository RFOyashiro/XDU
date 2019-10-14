#ifndef MEMORIACARD_H
#define MEMORIACARD_H
#include <string>
#include <map>
#include <fstream>

struct CardM {
    std::string Name;
    std::string Rarity;
};

class MemoriaCard
{
    public:
        MemoriaCard();
        std::string GetName(unsigned CardNumber) {return List.find(CardNumber)->second.Name;}
        std::string GetRarity(unsigned CardNumber) {return List.find(CardNumber)->second.Rarity;}

    private:
        std::map<unsigned, CardM> List;
};
#endif // MEMORIACARD_H
