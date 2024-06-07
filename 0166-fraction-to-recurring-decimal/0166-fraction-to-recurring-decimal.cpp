class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
        {
            return "0";
        }
        string result;
        if (numerator > 0 ^ denominator > 0)
        {
            result += "-";
        }
        long nume = labs(numerator);
        long denomi = labs(denominator);
        long quotient = nume / denomi;
        long remainder = nume % denomi;
        result += to_string(quotient);
        if (remainder == 0)
        {
            return result;
        }
        result += ".";
        unordered_map<long, int> remainderMap;
        while (remainder != 0)
        {
            if (remainderMap.find(remainder) != remainderMap.end())
            {
                result.insert(remainderMap[remainder], "(");
                result += ")";
                break;
            }
            remainderMap[remainder] = result.size();
            remainder *= 10;
            quotient = remainder / denomi;
            result += to_string(quotient);
            remainder = remainder % denomi;
        }
        return result;
    }
};