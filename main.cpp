#include "Header.h"


int main() {
	
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));
	double v, l1, u1;
	int flag;
	std::cout << "Введите '0' если хотите считать данные из файла, '1' если ввести из консоли > ";
	
	std::cin >> flag;
	while (std::cin.fail()) {							// проверка вводимых данных
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Ошибка ввода. Введите значениe повторно > ";
		std::cin >> flag;
	}
	std::cout << std::endl;
	switch (flag)
	{
		case 0:
		{
			std::cout << "Введите название файла > ";
			std::string s;
			std::cin >> s;
			std::cout << std::endl;
			Std_distr distr(s);			
			auto vec = distr.Create_std_set(1000);
			auto func = distr.Create_std_graph(vec, 1000);
			std::ofstream file1("standart_distr.txt");
			for (int i = 0; i < func.size(); ++i) {
				file1 << func[i].first << "\t" << func[i].second << std::endl;
			}

			// output console print
			std::cout << "Для стандартного распределения ";
			std::cout << "Дисперсия равна: " << distr.Modified_Dispersion_calc() << std::endl
				<< "Эксцесс:  " << distr.Excess_calc() << std::endl
				<< "Плотность распределения в точке " << distr.get_shift() << " равна: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
				<< "Мат. Ожидание:  " << distr.Modified_Expected_value_calc() << std::endl
				<< "Асимметрия:  " << distr.Asymmetry_calc() << std::endl;

			// output data save
			std::ofstream out("output.txt"); // окрываем файл для чтения
			if (out.is_open())
			{
				out << "Дисперсия равна: " << distr.Modified_Dispersion_calc() << std::endl
					<< "Эксцесс:  " << distr.Excess_calc() << std::endl
					<< "Плотность распределения в точке " << distr.get_shift() << " равна: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
					<< "Мат. Ожидание:  " << distr.Modified_Expected_value_calc() << std::endl
					<< "Асимметрия:  " << distr.Asymmetry_calc() << std::endl;
			}
			out.close();     // закрываем файл
		}
		break;

		case 1:
		{
			std::cout << "Введите: v (v > 0), l, u> ";
			std::cin >> v >> l1 >> u1;
			while (std::cin.fail()) {							// проверка вводимых данных
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Ошибка ввода. Введите значения повторно. > ";
				std::cin >> v >> l1 >> u1;
			}
			while (v <= 0) {
				std::cout << "Ошибка в значении параметра формы. Введите значение повтороно > ";
				std::cin >> v;
			}
			Std_distr distr(u1, l1, v); 
			auto vec = distr.Create_std_set(1000);
			auto func = distr.Create_std_graph(vec, 1000);
			std::ofstream file1("standart_distr.txt");
			for (int i = 0; i < func.size(); ++i) {
				file1 << func[i].first << "\t" << func[i].second << std::endl;
			}

			// output console print
			std::cout << "Для стандартного распределения ";
			std::cout << "Дисперсия равна: " << distr.Modified_Dispersion_calc() << std::endl
				<< "Эксцесс:  " << distr.Excess_calc() << std::endl
				<< "Плотность распределения в точке " << distr.get_shift() << " равна: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
				<< "Мат. Ожидание:  " << distr.Modified_Expected_value_calc() << std::endl
				<< "Асимметрия:  " << distr.Asymmetry_calc() << std::endl;

			// output data save
			std::ofstream out("output.txt"); // окрываем файл для чтения
			if (out.is_open())
			{
				out << "Дисперсия равна: " << distr.Modified_Dispersion_calc() << std::endl
					<< "Эксцесс:  " << distr.Excess_calc() << std::endl
					<< "Плотность распределения в точке " << distr.get_shift() << " равна: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
					<< "Мат. Ожидание:  " << distr.Modified_Expected_value_calc() << std::endl
					<< "Асимметрия:  " << distr.Asymmetry_calc() << std::endl;
			}
			out.close();     // закрываем файл
		}
		break;

		[[unlikely]] default:
			std::cout << "Введен некорректный код операции!";
			exit(0);
			break;
	}
	
	return 0;
}