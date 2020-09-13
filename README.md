# Gilded Rose Refactoring Kata

This is my take on the Gilded Rose Refactoring Kata. (Currently only in Python)

This Kata was originally created by Terry Hughes (http://twitter.com/TerryHughes). It is already on GitHub [here](https://github.com/NotMyself/GildedRose). See also [Bobby Johnson's description of the kata](http://iamnotmyself.com/2011/02/13/refactor-this-the-gilded-rose-kata/).

Remarks:
1. I think `update_quality` is a bad choice for a function name. In addition to updating the quality, it also has the side effect of reducing the sell_in of the item. I'd classify this as unexpected behaviour.
2. All subclasses of CategorizedItem, except for Legendary items, have the same `update_sell_in` implementation. One could argue that this should be the default behaviour and that it should be moved to the base class. However, I chose to make the `update_quality` and `update_sell_in` abstract because I think it's more clear to explicitly specify the behaviour of the different CategorizedItems, eventhough this means having (a small amount of) duplicate code.

## Better Code Hub

This code has been analysed by [Better Code Hub](https://bettercodehub.com). For reference, the original score before refactoring was 5.

[![BCH compliance](https://bettercodehub.com/edge/badge/QuintenDV/GildedRose-Refactoring-Kata?branch=master)](https://bettercodehub.com/)
