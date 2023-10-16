#include "Header.h"
#include <fstream>
#include <string>

int main() {
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));
	double v, l1, u1;
	Std_distr distr;
	int flag;
	std::cout << "������� '0' ���� ������ ������� ������ �� �����, '1' ���� ������ �� ������� > ";
	std::cin >> flag;
	while (std::cin.fail()) {							// �������� �������� ������
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "������ �����. ������� �������e �������� > ";
		std::cin >> flag;
	}
	std::cout << std::endl;
	switch (flag)
	{
		case 0:
		{
			double symbol;
			double mass[3];
			std::ifstream in("input.txt"); // ��������� ���� ��� ������
			if (in.is_open())
			{	
				for (int i = 0; i < 3; i++)
				{
					in >> symbol;
					while (in.fail())
					{
						in.clear();
						in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "������ � ������ �� �������� �����. ������������ ����� �� ���������. "<<std::endl;
						exit(0);
					}
					mass[i] = symbol;
				}
			}
			in.close();     // ��������� ����
			v= mass[0];
			u1 = mass[1];
			l1 = mass[2];
		}
		break;

		case 1:

			std::cout << "�������: v (v > 0), l, u> ";
			std::cin >> v >> l1 >> u1;
			while (std::cin.fail()) {							// �������� �������� ������
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������ �����. ������� �������� �������� > ";
				std::cin >> v >> l1 >> u1;
			}
			while (v <= 0) {
				std::cout << "������ ����� v. ������� �������� ��������� > ";
				std::cin >> v;
			}
			break;

		[[unlikely]] default:
			std::cout << "������ ������������ ��� ��������!";
			exit(0);
			break;
	}
	
	distr.set_form(v);
	distr.set_shift(u1);
	distr.set_scale(l1);
	auto vec = distr.Create_std_set(1000);
	auto func = distr.Create_std_graph(vec, 1000);
	std::ofstream file1("standart_distr.txt");
	for (int i = 0; i < func.size(); ++i) {
		file1 << func[i].first << "\t" << func[i].second << std::endl;
	}

														// output console print
	std::cout << "��� ������������ ������������� ";
	std::cout << "��������� �����: " << distr.Modified_Dispersion_calc() << std::endl
			  << "�������:  " << distr.Excess_calc() << std::endl
			  << "��������� ������������� � ����� " << u1 << " �����: " << distr.Modified_Density_calc(u1) << std::endl
			  << "���. ��������:  "<< distr.Modified_Expected_value_calc() << std::endl
			  << "����������:  " << distr.Asymmetry_calc() << std::endl;

														// output data save
	std::ofstream out("output.txt"); // �������� ���� ��� ������
	if (out.is_open())
	{
		out << "��������� �����: " << distr.Modified_Dispersion_calc() << std::endl
			<< "�������:  " << distr.Excess_calc() << std::endl
			<< "��������� ������������� � ����� " << u1 << " �����: " << distr.Modified_Density_calc(u1) << std::endl
			<< "���. ��������:  " << distr.Modified_Expected_value_calc() << std::endl
			<< "����������:  " << distr.Asymmetry_calc() << std::endl;
	}
	out.close();     // ��������� ����
	return 0;
}