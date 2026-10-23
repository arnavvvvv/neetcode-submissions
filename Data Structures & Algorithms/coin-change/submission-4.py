
class Solution:
    
    def coinChange(self, coins: List[int], amount: int) -> int:
        cache = {}
        def solve(amount):
            if amount == 0:
                return 0
            if cache.get(amount, -2) != -2: 
                return cache[amount]
            count = 10001
            for coin in coins:
                if coin <= amount:
                    count_down = solve(amount - coin)
                    if count_down != -1:
                        count = min(count, 1 + count_down)
            
            cache[amount] = -1 if count == 10001 else count 
            return cache[amount]
        return solve(amount)