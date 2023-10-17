#include "Header.h"

	void Std_distr::set_shift(double shift) {
		Std_distr::u = shift;
	}
	void Std_distr::set_scale(double scale) {
		Std_distr::l = scale;
	}
	
	void Std_distr::set_form(double form) {
		Std_distr::v = form;
	}

	double Std_distr::get_shift() {
		return Std_distr::u;
	}
	double Std_distr::get_scale() {
		return Std_distr::l;
	}
	double Std_distr::get_form() {
		return Std_distr::v;
	}

	double Std_distr::Density_calc(double x) {
		double density = (Std_distr::v / (2 * tgamma(1 / Std_distr::v)) * exp(-pow(abs(x), Std_distr::v)));
		/*double density = (v / (2 * tgamma(1 / v)) * exp(exp(v * (-log(abs(x))))));*/
		return density;
	}

	double Std_distr::Standart(double x) {
		double xmod = ((x - Std_distr::u) / Std_distr::l);
		return xmod;
	}

	double Std_distr::Modified_Density_calc(double x) {
		double xmod = Standart(x);
		double mod_density = (Std_distr::v / (2 * tgamma(1 / Std_distr::v)) * exp(-pow(abs(xmod), Std_distr::v))) / Std_distr::l;
		//double mod_density = (v / (2 * tgamma(1 / v)) * exp(exp(v*(-log(abs(x)))))) / l;
		return mod_density;
	}
	double Std_distr::Expected_value() { return 0; }

	double Std_distr::Modified_Expected_value_calc() {
		double mod_expected_value = Expected_value() + Std_distr::u;
		return mod_expected_value;
	}

	double Std_distr::Dispersion_calc() {
		double dispersion = (tgamma(3 / Std_distr::v) / tgamma(1 / Std_distr::v));
		return dispersion;
	}

	double Std_distr::Modified_Dispersion_calc() {
		double mod_dispersion = (tgamma(3 / Std_distr::v) / tgamma(1 / Std_distr::v)) * pow(Std_distr::l, 2);
		return mod_dispersion;
	}

	double Std_distr::Excess_calc() {
		double excess = ((tgamma(5 / Std_distr::v) * tgamma(1 / Std_distr::v) / pow(tgamma(3 / Std_distr::v), 2)) - 3);
		return excess;
	}

	double Std_distr::Asymmetry_calc() { return 0; }

	std::vector<double> Std_distr::Modified_Func_calc(double x) { //подсчет всех параметров для модифицированной функции
		std::vector<double> vec = { Modified_Dispersion_calc(), Excess_calc(), Modified_Density_calc(x), Modified_Expected_value_calc() };
		return vec;
	}
	double Std_distr::Randomizer() {
		double r;
		do r = (double)rand() / RAND_MAX; while (r == 0 || r == 1);
		return r;
	}

														// part of an algorithm for v in range [1;2)
	double Std_distr::Random_item12() {
		double r = Randomizer();
		double a = (1 / Std_distr::v) - 1;
		//double b = 1 / (exp((1 / v) * log(v)));
		double b = 1 / (pow(Std_distr::v, 1 / Std_distr::v));
		double x = 0;
		if (r <= 0.5) {
			x = b * log(2 * r);
		}
		else if (r > 0.5) {
			x = -b * log(2 * (1 - r));
		}
		double r2 = Randomizer();
		if (log(r2) <= (exp(Std_distr::v * (-log(abs(x)))) + (abs(x) / b) + a)) { return x; }
		//if (log(r2) <= (-pow(abs(x), v) + (abs(x) / b) + a)) { return x; }
		else { return  Random_item12(); }
	}

													// part of an algorithm for v in range [2; inf)
	double Std_distr::Random_item2() {
		double a = (1 / Std_distr::v) - 0.5;
		//double b = 1 / (exp((1 / v) * log(v)));
		double b = 1 / (pow(Std_distr::v, 1 / Std_distr::v));
		double c = 2 * pow(b, 2);
		double r = Randomizer();
		double r2 = Randomizer();
		double x = b * sqrt(-2 * log(r)) * cos(2 * M_PI * r2);
		double r3 = Randomizer();
		if (log(r3) <= (exp(Std_distr::v * (-log(abs(x)))) + (pow(x, 2) / c) + a)) { return x; }
		/*if (log(r3) <= (-pow(abs(x), v) + (pow(x, 2) / c) + a)) { return x; }*/
		else { return Random_item2(); }
	}
													// function for the whole algorithm use
	double Std_distr::Random_item() {
		double result=0;/////////////////////////////////
		if ((1 <= Std_distr::v) && (Std_distr::v < 2)) { result = Random_item12(); }
		else if (Std_distr::v >= 2) { result = Random_item2(); }
		return ((result * Std_distr::l + Std_distr::u));
	}

	std::vector<double> Std_distr::Create_std_set(const int n) {
		std::vector<double> result;
		for (int i = 0; i < n; i++) {
			result.push_back(Random_item());
		}
		sort(result.begin(), result.end());
		return result;
	}

	std::vector<std::pair<double, double>> Std_distr::Create_std_graph(std::vector<double> vec, const int n) {
		std::vector<std::pair<double, double>> result;
		for (int i = 0; i < n; ++i) {
			result.push_back(std::make_pair(vec[i], Modified_Density_calc(vec[i])));
		}
		return result;
	}
