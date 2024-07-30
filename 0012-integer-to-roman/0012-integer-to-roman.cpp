class Solution {
public:
    string intToRoman(int num) {
        string res = "";  // Initialize the result string
        // Arrays to store Roman numeral symbols and their corresponding values
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
                         
        // Iterate through each symbol and its value
        for(int i = 0; num != 0; i++) {
            // While the number is greater than or equal to the current value
            while(num >= val[i]) {
                num -= val[i];  // Subtract the value from the number
                res += symbol[i];  // Append the symbol to the result string
            }
        }
        return res;  // Return the final Roman numeral string
    }
};
