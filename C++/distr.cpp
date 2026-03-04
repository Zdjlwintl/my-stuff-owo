// 12:12

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

void option1() {
	double x, m, var;
	cout << "Enter the values of x, mean and variance: " << flush;
	cin >> x >> m >> var;
	double z = (x - m)/var;
	cout << "P(Z < " << z << ") = " << cdf(z) << endl;
}

void option2() {
	double x, m, var;
	cout << "Enter the values of x, mean and variance: " << flush;
	cin >> x >> m >> var;
	double z = (x - m)/var;
	cout << "P(Z > " << z << ") = 1 - P(Z < " << z << ") = " << 1 - cdf(z) << endl;
}

void option3() {
	double xUpper, xLower, m, var;
	cout << "Enter the values of the lower bound of x, upper bound of x, mean and variance: " << flush;
	cin >> xLower >> xUpper >> m >> var;
	double zUpper = (xUpper - m)/var;
	double zLower = (xLower - m)/var;
	cout << "P(" << zLower << " < Z < " << zUpper << ") = " << cdf(zUpper) - cdf(zLower) << endl;
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
