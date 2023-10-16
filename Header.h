#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>

class Std_distr {
private:
	double u, l, v;
public:
	Std_distr() {}; // конструктор по умолчанию

	Std_distr(double shift0, double scale0, double form0) { //  онструктор лего
		u = shift0;
		l = scale0;
		v = form0;
	};

	Std_distr(FILE* stram) { // конструктор из файла 
		//дописать
	};
	~Std_distr() // деструктор
	{
		std::cout << "Memory has been cleaned. Good bye." << std::endl;
	};
	void set_shift(double shift);
	void set_scale(double scale);
	void set_form(double form);
	double get_shift();
	double get_scale();
	double get_form();
	double Density_calc(double x);

	double Standart(double x);

	double Modified_Density_calc(double x);
	double Expected_value();

	double Modified_Expected_value_calc();

	double Dispersion_calc();

	double Modified_Dispersion_calc();

	double Excess_calc();

	double Asymmetry_calc();

	std::vector<double> Modified_Func_calc(double x);
	double Randomizer();
	// part of an algorithm for v in range [1;2)
	double Random_item12();
	// part of an algorithm for v in range [2; inf)
	double Random_item2();
	// function for the whole algorithm use
	double Random_item();

	std::vector<double> Create_std_set(const int n);

	std::vector<std::pair<double, double>> Create_std_graph(std::vector<double> vec,const int n);
};