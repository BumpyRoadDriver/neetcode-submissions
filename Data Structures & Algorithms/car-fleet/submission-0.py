class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        zipped = sorted(zip(position, speed), reverse = True) 
        t = (target - zipped[0][0])/zipped[0][1]
        ans = 1  

        for i in range(1, len(zipped)):
            pos, speed = zipped[i] 
            if ((speed * t) + pos < target):
                ans+=1 
                t = (target-pos)/speed 

        return ans

    
        