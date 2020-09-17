from item import Item
from categorized_items.normal_item import NormalItem
from categorized_items.backstage_pass import BackstagePass
from categorized_items.legendary_item import LegendaryItem
from categorized_items.well_aging_cheese import WellAgingCheese
from categorized_items.conjured_item import ConjuredItem

SPECIAL_ITEMS = {
    "Backstage passes to a TAFKAL80ETC concert": BackstagePass,
    "Sulfuras, Hand of Ragnaros": LegendaryItem,
    "Aged Brie": WellAgingCheese,
    "Conjured example item": ConjuredItem,
}

class CategorizedItemFactory:
    def _from_item_prefix(item):
        if item.name.startswith("Backstage passes"):
            return BackstagePass(item)
        if item.name.startswith("Conjured"):
            return ConjuredItem(item)
        return None

    def _from_special_item_list(item):
        categorized_item_class = SPECIAL_ITEMS.get(item.name, NormalItem)
        return categorized_item_class(item)

    def from_item(item):
        categorized_item = CategorizedItemFactory._from_item_prefix(item)
        if categorized_item != None:
            return categorized_item

        categorized_item = CategorizedItemFactory._from_special_item_list(item)
        return categorized_item