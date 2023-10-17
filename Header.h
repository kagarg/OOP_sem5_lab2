#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <string>
#include <fstream>

class Std_distr {
private:
	double u, l, v;
	double Standart(double x);
	double Density_calc(double x);
	double Dispersion_calc();
	double Expected_value();
	double Randomizer();
	// part of an algorithm for v in range [1;2)
	double Random_item12();
	// part of an algorithm for v in range [2; inf)
	double Random_item2();
	// function for the whole algorithm use
	double Random_item();
	
public:
	Std_distr() {
		u = 1;
		l = 1;
		v = 1;
	}; // конструктор по умолчанию

	Std_distr(double shift0, double scale0, double form0) { // Конструктор лего
		u = shift0;
		l = scale0;
		v = form0;
	};

	Std_distr(std::string File_name) { // конструктор из файла 
		double symbol;
		double mass[3];
		std::ifstream in(File_name); // открываем файл для чтения
		if (in.is_open())
		{	
			for (int i = 0; i < 3; i++)
			{
				in >> symbol;
				while (in.fail())
				{
					in.clear();
					in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Ошибка в данных из входного файла. Производится выход из программы. "<<std::endl;
					exit(0);
				}
				mass[i] = symbol;
			}
		}
		else { std::cout << "Неверное имя файла"; exit(0); }
		in.close();     // закрываем файл
		Std_distr::set_form(mass[0]);
		if (mass[0] > 0) { Std_distr::set_form(mass[0]); }
		else {
			std::cout << "Ошибка в значении параметра формы. Производится выход из программы. ";
			exit(0);
		}
		Std_distr::set_shift(mass[1]);
		Std_distr::set_scale(mass[2]);
	}

	~Std_distr() // деструктор
	{
		std::cout << "Memory has been cleaned. Good bye." << std::endl;
	}

	void set_shift(double shift);
	void set_scale(double scale);
	void set_form(double form);
	double get_shift();
	double get_scale();
	double get_form();
	double Modified_Density_calc(double x);
	double Modified_Expected_value_calc();
	double Modified_Dispersion_calc();
	double Excess_calc();
	double Asymmetry_calc();
	std::vector<double> Create_std_set(const int n);
	std::vector<std::pair<double, double>> Create_std_graph(std::vector<double> vec,const int n);
};