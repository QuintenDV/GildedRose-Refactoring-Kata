from item import Item
from categorized_items.normal_item import NormalItem
from categorized_items.backstage_pass import BackstagePass
from categorized_items.legendary_item import LegendaryItem
from categorized_items.well_aging_cheese import WellAgingCheese

SPECIAL_ITEMS = {
    "Backstage passes to a TAFKAL80ETC concert": BackstagePass,
    "Sulfuras, Hand of Ragnaros": LegendaryItem,
    "Aged Brie": WellAgingCheese,
}

class CategorizedItemFactory:
    @classmethod
    def from_item(cls, item):
        categorized_item_class = SPECIAL_ITEMS.get(item.name, NormalItem)
        categorized_item = categorized_item_class(item)
        return categorized_item

