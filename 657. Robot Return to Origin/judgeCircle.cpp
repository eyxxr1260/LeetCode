class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizen = 0;
        for (char c : moves) {
            if (c == 'D')
                vertical++;
            else if (c == 'U')
                vertical--;
            else if (c == 'R')
                horizen++;
            else if (c == 'L')
                horizen--;
        }
        return (vertical == 0) && (horizen == 0);
    }
};