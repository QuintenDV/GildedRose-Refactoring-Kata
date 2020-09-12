# -*- coding: utf-8 -*-
from categorized_item import CategorizedItem

class BackstagePass(CategorizedItem):
    def __init__(self, item):
        super().__init__(item)

    def update_quality(self):
        amount_to_increase = self._calculate_amount_to_increase()
        self.increase_quality(amount_to_increase)

        self.decrease_sell_in()
        if self.sell_in < 0:
            self.quality = 0

    def _calculate_amount_to_increase(self):
        amount_to_increase = 1
        if self.sell_in < 11:
            amount_to_increase += 1
        if self.sell_in < 6:
            amount_to_increase += 1
        return amount_to_increase


