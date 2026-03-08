/* Begun on 12:12, ended 12:50; today is 03/04/26
This is a little calculator made for normal distribution calculations to make my life easier xd
the issue is the table on my book specifically uses 3 decimal places for the z-score,
and 4 decimal places for the probabilities.
at worst though i'd be off by +- 0.001 or +- 0.0001 lol

today is 03/08/26, finished editing at 21:18
well. i tried to make the probabilities and z values to 4 and 3 d.p. respectively, kinda not the best idea since Lol,
also it took me so long to realise it asked for var yet divided (x - mean) by variance LOL,
so i decided to just add an extra input to ask to use variance or stdev (cuz i'm the one most likely to actually use this xd)
*/
#include <iostream>
#include <cmath>

using namespace std;

double cdf(double z) {
        return 0.5 * (1.0 + erf(z/sqrt(2.0)));
}

double inverse(double p) {
    static const double a1 = -3.969683028665376e+01;
    static const double a2 =  2.209460984245205e+02;
    static const double a3 = -2.759285104469687e+02;
    static const double a4 =  1.383577518672690e+02;
    static const double a5 = -3.066479806614716e+01;
    static const double a6 =  2.506628277459239e+00;

    static const double b1 = -5.447609879822406e+01;
    static const double b2 =  1.615858368580409e+02;
    static const double b3 = -1.556989798598866e+02;
    static const double b4 =  6.680131188771972e+01;
    static const double b5 = -1.328068155288572e+01;

    static const double c1 = -7.784894002430293e-03;
    static const double c2 = -3.223964580411365e-01;
    static const double c3 = -2.400758277161838e+00;
    static const double c4 = -2.549732539343734e+00;
    static const double c5 =  4.374664141464968e+00;
    static const double c6 =  2.938163982698783e+00;

    static const double d1 =  7.784695709041462e-03;
    static const double d2 =  3.224671290700398e-01;
    static const double d3 =  2.445134137142996e+00;
    static const double d4 =  3.754408661907416e+00;

    const double plow  = 0.02425;
    const double phigh = 1 - plow;

    double q, r;
    if (p < plow) {
        q = sqrt(-2*log(p));
        return (((((c1*q + c2)*q + c3)*q + c4)*q + c5)*q + c6) /
               ((((d1*q + d2)*q + d3)*q + d4)*q + 1);
    }
    else if (p > phigh) {
        q = sqrt(-2*log(1-p));
        return -(((((c1*q + c2)*q + c3)*q + c4)*q + c5)*q + c6) /
                 ((((d1*q + d2)*q + d3)*q + d4)*q + 1);
    }
    else {
        q = p - 0.5;
        r = q*q;
        return (((((a1*r + a2)*r + a3)*r + a4)*r + a5)*r + a6)*q /
               (((((b1*r + b2)*r + b3)*r + b4)*r + b5)*r + 1);
    }
}

double roundTo(double value, int places) {
        return round(pow(10, places) * value) / pow(10, places);
}

double z_val(char mode) {
        double x, m, std;
        if (mode == 's') {
                cout << "Enter the values of x, mean and stdev: " << flush;
                cin >> x >> m >> std;
        } else if (mode == 'v') {
                cout << "Enter the values of x, mean and var: " << flush;
                cin >> x >> m >> std;
                std = sqrt(std);
        }
        else { return 1; }
        return roundTo((x - m)/std, 3);
}
void option1() {
        char mode;
        cout << "Using var [v] or stdev [s]? " << flush;
        cin >> mode;
        double z = z_val(mode);
        cout << "P(Z < " << z << ") = " << roundTo(cdf(z), 4) << endl;
}

void option2() {
        char mode;
        cout << "Using var [v] or stdev [s]? " << flush;
        cin >> mode;
        double z = z_val(mode);
        cout << "P(Z > " << z << ") = 1 - P(Z < " << z << ") = " << roundTo(cdf(-z), 4) << endl;
}

void option3() {
        double xUpper, xLower, m, std;
        char mode;
        cout << "Using var [v] or stdev [s]? " << flush;
        cin >> mode;
        if (mode == 's') {
                cout << "Enter the values of the lower bound of x, upper bound of x, mean and stdev: " << flush;
                cin >> xLower >> xUpper >> m >> std;
        } else if (mode == 'v') {
                cout << "Enter the values of the lower bound of x, upper bound of x, mean and var: " << flush;
                cin >> xLower >> xUpper >> m >> std;
                std = sqrt(std);
        }
        double zUpper = roundTo((xUpper - m)/std, 3);
        double zLower = roundTo((xLower - m)/std, 3);

        cout << "P(" << zLower << " < Z < " << zUpper << ") = " << roundTo(cdf(zUpper), 4) - roundTo(cdf(zLower), 4) << endl;
}

void option4() {
        double Fz;
        cout << "Enter value of Fi(z): " << flush;
        cin >> Fz;
        if (Fz >= 0.5) {
                cout << "Fi^-1(" << Fz << ") = " << inverse(Fz) << endl;
        } else {
                cout << "Fi^-1(" << Fz << ") = - Fi^-1(" << 1 - Fz << ") = " << -(inverse(1-Fz)) << endl;
        }
}
int main() {
        int option;

        cout << "Enter an option:\n1. Normal CDF P(X < x)\n2. Normal CDF P(X > x)\n3. Ranged CDF P(xUpper < X < xLower)\n4. Inverse CDF Fi^-1" << endl;
        cin >> option;

        switch (option) {
                case 1: option1(); break;
                case 2: option2(); break;
                case 3: option3(); break;
                case 4: option4(); break;
                default: cout << "Invalid option." << endl;
        }
        return 0;
}

// 12:50
