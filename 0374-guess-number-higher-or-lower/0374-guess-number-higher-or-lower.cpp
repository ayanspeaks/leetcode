/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return       -1 if num is higher than the picked number
 *               1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int s = 0;              // Start of the search range
        int e = n;              // End of the search range

        while (s <= e) {
            int mid = s + (e - s) / 2; // Compute the middle point of the range

            int pick = guess(mid); // Guess the middle number

            if (pick == 0) {
                return mid;       // The guessed number is correct
            } else if (pick == -1) {
                e = mid - 1;     // The guessed number is too high, search in the left half
            } else {
                s = mid + 1;     // The guessed number is too low, search in the right half
            }
        }

        return -1; // This line should not be reached if the input guarantees that the number exists
    }
};
