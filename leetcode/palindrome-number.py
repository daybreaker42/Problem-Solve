class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        if x < 10:
            return True
        length = 1
        while length <= x:
            length *= 10
        
        length /= 10

        top_number = length
        bot_number = 1

        solution = True

        while top_number > bot_number:
            top = 0
            bot = 0
            if top_number * 10 >  x:
                top = x // top_number
            else:
                top = x // top_number - ((x // (top_number * 10)) * 10)
            
            if bot_number * 10 > x:
                bot = x // bot_number
            else:
                bot = x // bot_number - ((x // (bot_number * 10)) * 10)
                
            if top != bot:
                solution = False
                break

            top_number /= 10
            bot_number *= 10

        return solution
    
if __name__ == "__main__":
    solution = Solution()
    print(solution.isPalindrome(12321))
    # print(solution.isPalindrome(-121))
    # print(solution.isPalindrome(10))