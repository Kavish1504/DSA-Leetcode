class Solution {
public:
    bool isNumber(string s) {
      int i = 0;
        int n = s.length();

        // Skip leading spaces
        while (i < n && isspace(s[i])) i++;
        if (i == n) return false; // String is all spaces

        // Variables to track valid components
        bool hasDigits = false, hasE = false, hasDot = false;

        while (i < n) {
            char ch = s[i];

            if (isdigit(ch)) {
                hasDigits = true;
            } else if (ch == '.') {
                // A dot is invalid if there's already a dot or an exponent
                if (hasDot || hasE) return false;
                hasDot = true;
            } else if (ch == 'e' || ch == 'E') {
                // Exponent is invalid if there's already an exponent or no digits before it
                if (hasE || !hasDigits) return false;
                hasE = true;
                hasDigits = false; // Reset digits for the exponent part
            } else if (ch == '+' || ch == '-') {
                // '+'/'-' is valid only at the start or immediately after 'e/E'
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
            } else if (isspace(ch)) {
                // Skip trailing spaces
                while (i < n && isspace(s[i])) i++;
                return i == n;
            } else {
                // Invalid character
                return false;
            }
            i++;
        }
        return hasDigits;
    }
};