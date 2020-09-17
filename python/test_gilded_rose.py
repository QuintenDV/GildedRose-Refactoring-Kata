# -*- coding: utf-8 -*-
import unittest

from gilded_rose import GildedRose
from item import Item

class GildedRoseTest(unittest.TestCase):

    def test_normal_items(self):
        n_iterations = 5
        item_before_test = [
            Item(name="+5 Dexterity Vest", sell_in=10, quality=20),
            Item(name="Helmet of Intelligence", sell_in=2, quality=50),
            Item(name="Spoiled Fried Chicken", sell_in=-5, quality=5),
            Item(name="Unicorn Horn", sell_in=0, quality=10)
            ]
        target_items = [
            Item(name="+5 Dexterity Vest", sell_in=5, quality=15),
            Item(name="Helmet of Intelligence", sell_in=-3, quality=42),
            Item(name="Spoiled Fried Chicken", sell_in=-10, quality=0),
            Item(name="Unicorn Horn", sell_in=-5, quality=0),
            ]

        GildedRoseTest.run_gilded_rose(
            item_before_test,
            target_items,
            n_iterations)

    def test_Legendary_items(self):
        n_iterations = 5
        items_before_test = [
            Item(name="Sulfuras, Hand of Ragnaros", sell_in=0, quality=80),
            ]
        target_items = [
            Item(name="Sulfuras, Hand of Ragnaros", sell_in=0, quality=80),
            ]

        GildedRoseTest.run_gilded_rose(
            items_before_test,
            target_items,
            n_iterations)

    def test_well_aging_items(self):
        n_iterations = 5
        items_before_test = [
            Item(name="Aged Brie", sell_in=2, quality=0),
            ]
        target_items = [
            Item(name="Aged Brie", sell_in=-3, quality=8),
            ]

        GildedRoseTest.run_gilded_rose(
            items_before_test,
            target_items,
            n_iterations)

    def test_backstage_passes(self):
        n_iterations = 5
        items_before_test = [
            Item(name="Backstage passes to an Iron Maiden concert", sell_in=12, quality=10),
            Item(name="Backstage passes to a Slayer concert", sell_in=7, quality=10),
            Item(name="Backstage passes to a Taylor Swift concert", sell_in=2, quality=49),
            ]
        target_items = [
            Item(name="Backstage passes to an Iron Maiden concert", sell_in=7, quality=18),
            Item(name="Backstage passes to a Slayer concert", sell_in=2, quality=23),
            Item(name="Backstage passes to a Taylor Swift concert", sell_in=-3, quality=0),
            ]

        GildedRoseTest.run_gilded_rose(
            items_before_test,
            target_items,
            n_iterations)

    def test_conjured_items(self):
        n_iterations = 5
        items_before_test = [
            Item(name="Conjured Mana Cake", sell_in=10, quality=20),
            Item(name="Conjured Socks", sell_in=2, quality=20),
            ]
        target_items = [
            Item(name="Conjured Mana Cake", sell_in=5, quality=10),
            Item(name="Conjured Socks", sell_in=-3, quality=4),
            ]

        GildedRoseTest.run_gilded_rose(
            items_before_test,
            target_items,
            n_iterations)

    def run_gilded_rose(before_items, after_items, n_iterations):
        gilded_rose = GildedRose(before_items)

        for _ in range(n_iterations):
            gilded_rose.update_quality()

        for i1,i2 in zip(before_items, after_items):
            GildedRoseTest._assert_items_are_equal(i1, i2)

    def _assert_items_are_equal(item1, item2):
        assert item1.name == item2.name, f"Item names don't match: {item1.name}, {item2.name} "
        assert item1.sell_in == item2.sell_in, f"[{item1.name}]: sell_in values don't match: {item1.sell_in}, {item2.sell_in} "
        assert item1.quality == item2.quality, f"[{item1.name}]: qualities don't match: {item1.quality}, {item2.quality} "

if __name__ == '__main__':
    unittest.main()
