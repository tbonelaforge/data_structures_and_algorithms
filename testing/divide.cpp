void divide(int dividend, int divisor, float &quotient, bool &error) {
    if (divisor) {
        quotient = float(dividend) / float(divisor);
        //error = false;
    }
    else {
        error = true;
    }
}
