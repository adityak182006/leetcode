int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long result = 0;

    // 1. Ignore leading whitespace
    while (s[i] == ' ') {
        i++;
    }

    // 2. Determine sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // 3. Convert characters to integer and handle overflow
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        result = result * 10 + digit;

        // 4. Check for 32-bit signed integer overflow/underflow
        if (sign * result >= INT_MAX) {
            return INT_MAX;
        }
        if (sign * result <= INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return (int)(sign * result);
    
}