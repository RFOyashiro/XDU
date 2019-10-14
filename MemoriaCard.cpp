#include "MemoriaCard.h"

MemoriaCard::MemoriaCard()
{
    std::string line;
    std::ifstream Input ("MemoriaCardList.txt");
    std::getline(Input, line);
    while (line != "0") {
        CardM card;
        unsigned CardNumber = std::stoi(line);
        std::getline(Input, line);
        card.Name = line;
        std::getline(Input, line);
        card.Rarity = line;
        List.insert(std::make_pair(CardNumber, card));
        std::getline(Input, line);
    }
}
