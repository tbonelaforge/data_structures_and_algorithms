class FractionType {
 public:
    void Initialize(int numerator, int denominator);

    bool isZero();

    bool isNotProper();

    int getNumerator();

    int getDenominator();

    int convertToProper();

 private:
    int numerator;
    int denominator;
};
