class Solution:
    cache = {}
    def ways(self, s, i):
        if i == len(s):
            return 1
        if s[i] == '0':
            return 0
        if self.cache.get(i, -1) != -1:
            return self.cache[i]
        count = self.ways(s, i + 1)
        if i + 1 < len(s) and (s[i] == '1' or (s[i] == '2' and s[i + 1] < '7')):
            count += self.ways(s, i + 2)
        self.cache[i] = count
        return count
        

    def numDecodings(self, s: str) -> int:
        self.cache = {}
        return self.ways(s, 0)
        