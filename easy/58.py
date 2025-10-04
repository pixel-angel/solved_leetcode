class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        news=s.split()
        return(len(news[-1]))
        