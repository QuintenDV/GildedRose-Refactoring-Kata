# Gilded Rose Refactoring Kata - Python

## Remarks
1. I think `update_quality` is a bad choice for a function name. In addition to updating the quality, it also has the side effect of reducing the sell_in of the item. I'd classify this as unexpected behaviour.
2. All subclasses of CategorizedItem, except for Legendary items, have the same `update_sell_in` implementation. One could argue that this should be the default behaviour and that it should be moved to the base class. However, I chose to make the `update_quality` and `update_sell_in` abstract because I think it's more clear to explicitly specify the behaviour of the different CategorizedItems, eventhough this means having (a small amount of) duplicate code.