#include "Inventory.h"

using namespace std;

Inventory::Inventory() {
    Inventory::initAgedCheeses();
    Inventory::initLegendaries();
}

void Inventory::initAgedCheeses() {
    agedCheeses.insert("Aged Brie");
}

void Inventory::initLegendaries() {
    legendaries.insert("Sulfuras, Hand of Ragnaros");
}

bool Inventory::isAgedCheese(string itemName){
    return agedCheeses.count(itemName);
}

bool Inventory::isLegendary(string itemName){
    return legendaries.count(itemName);
}