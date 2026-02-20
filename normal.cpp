/* 10:41
Today is 02/20/26
So I had some math homework about normal distribution and thought Hey maybe I should write some code to help me
so I don't need to keep checking against The Table. and thus this was born.
Hardcoded for the specific questions I needed to answer lol, also I didn 't make the inverse function myself
cuz I didn't want to worry so much about it lol.
*/

#include <iostream>
#include <cmath>

using namespace std;

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

double cdf(double z) {
	return 0.5 * (1.0 + erf(z/sqrt(2.0)));

}
int main() {
	class z_range {
	public:
		double Lower;
		double Higher;
		
		double cdf_range() {
			return cdf(Higher) - cdf(Lower);
		}
	};

	class z_unknown { 
	public:
		bool isLower;
		double z_known;

		double find_c(double k) {
			if (isLower == true) {
				return inverse(cdf(z_known) - k);
			}
			else {
				return inverse(cdf(z_known) + k);
			}
		}
	};
	/*
	P(q < Z < s) = k;
	P(Z < s) - P(Z < q) = k;
		where q and k are known;
			let P(Z < q) = Q;
				P(Z < s) - Q = k;
				P(Z < s) = k + Q;

				s = P^-1(k+Q);	
		else
			where s and k are known;
			let P(Z < s) = S;
				S - P(Z < q) = k;
				P(Z < q) = S - k;

				q = P^-1(S-k);
	*/
		
	double z1[] = { 0.567, 2.468, 1.53, 0.077, -0.817, -2.009, -1.75, -0.013, 1.96, -2.576 };
	
	z_range z2[] = {
		{1.5 , 2.5},
		{0.046, 1.272},
		{1.645, 2.326},
		{1.282, 2.807},
		{0.746, 1.777},
		{0.337, 1.008},
		{-1.2, 1.2},
		{-1.667, 2.667},
		{-0.75, 1.6},
		{sqrt(2.0), sqrt(5.0)}
	};
	
	double p3[] = { 0.9087, 0.5442, 1-0.2743, 1-0.0298, 0.25, 0.3552, 1-0.9296, 1-0.648, 0.5*(0.9128+1), 0.5*(0.6994+1) };
	
	double p4[] = { 0.2673, 0.4968, 0.1408, 0.35, 0.6687, 0.9516, 0.888, 0.725, 0.6861, 0.0252 };
	
	z_unknown z4[] = {
		{true, 1.638},
		{true, 2.878},
		{false, 1.0},
		{false, 0.109},
		{true, 2.0},
		{true, 1.85},
		{false, -1.221},
		{false, -0.674},
		{false, -2.63},
		{false, -2.7}
	};

	cout << "Part 1" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Q" << i + 1 << ". P(Z < " << z1[i] << ") = " << cdf(z1[i]) << endl;
	}
	cout << endl;

	cout << "Part 2" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Q" << i + 1 << ". P(" << z2[i].Lower << " < Z < " << z2[i].Higher << ") = " << z2[i].cdf_range() << endl;
	}
	cout << endl;

	cout << "Part 3" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Q" << i + 1 << ". Fi^-1(" << p3[i] << ") = " << inverse(p3[i]) << endl;
	}
	cout << endl;
	
	double c_val[10];

	cout << "Part 4" << endl;
	for (int i = 0; i < 10; i++) {
		c_val[i] = z4[i].find_c(p4[i]);
		cout << "Q" << i + 1 << ". c = " << c_val[i] << endl;
	}

	cout << "\nOriginal questions for Part 4)" << endl;
	for (int i = 0; i < 10; i++) {
		if (z4[i].isLower == true) {
			cout << i + 1 << ". P(c < Z < " << z4[i].z_known << ") = " << p4[i] << "; c = ?" << endl;
		}
		else {
			cout << i + 1 << ". P(" << z4[i].z_known << " < Z < c) = " << p4[i] << "; c = ?" << endl;
		}
	}
	return 0;
}
// 11:01
