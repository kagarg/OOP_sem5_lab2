#include "Header.h"


int main() {
	
	setlocale(LC_ALL, "ru");
	srand((unsigned)time(0));
	double v, l1, u1;
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
			std::cout << "������� �������� ����� > ";
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
			std::cout << "��� ������������ ������������� ";
			std::cout << "��������� �����: " << distr.Modified_Dispersion_calc() << std::endl
				<< "�������:  " << distr.Excess_calc() << std::endl
				<< "��������� ������������� � ����� " << distr.get_shift() << " �����: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
				<< "���. ��������:  " << distr.Modified_Expected_value_calc() << std::endl
				<< "����������:  " << distr.Asymmetry_calc() << std::endl;

			// output data save
			std::ofstream out("output.txt"); // �������� ���� ��� ������
			if (out.is_open())
			{
				out << "��������� �����: " << distr.Modified_Dispersion_calc() << std::endl
					<< "�������:  " << distr.Excess_calc() << std::endl
					<< "��������� ������������� � ����� " << distr.get_shift() << " �����: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
					<< "���. ��������:  " << distr.Modified_Expected_value_calc() << std::endl
					<< "����������:  " << distr.Asymmetry_calc() << std::endl;
			}
			out.close();     // ��������� ����
		}
		break;

		case 1:
		{
			std::cout << "�������: v (v > 0), l, u> ";
			std::cin >> v >> l1 >> u1;
			while (std::cin.fail()) {							// �������� �������� ������
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������ �����. ������� �������� ��������. > ";
				std::cin >> v >> l1 >> u1;
			}
			while (v <= 0) {
				std::cout << "������ � �������� ��������� �����. ������� �������� ��������� > ";
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
			std::cout << "��� ������������ ������������� ";
			std::cout << "��������� �����: " << distr.Modified_Dispersion_calc() << std::endl
				<< "�������:  " << distr.Excess_calc() << std::endl
				<< "��������� ������������� � ����� " << distr.get_shift() << " �����: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
				<< "���. ��������:  " << distr.Modified_Expected_value_calc() << std::endl
				<< "����������:  " << distr.Asymmetry_calc() << std::endl;

			// output data save
			std::ofstream out("output.txt"); // �������� ���� ��� ������
			if (out.is_open())
			{
				out << "��������� �����: " << distr.Modified_Dispersion_calc() << std::endl
					<< "�������:  " << distr.Excess_calc() << std::endl
					<< "��������� ������������� � ����� " << distr.get_shift() << " �����: " << distr.Modified_Density_calc(distr.get_shift()) << std::endl
					<< "���. ��������:  " << distr.Modified_Expected_value_calc() << std::endl
					<< "����������:  " << distr.Asymmetry_calc() << std::endl;
			}
			out.close();     // ��������� ����
		}
		break;

		[[unlikely]] default:
			std::cout << "������ ������������ ��� ��������!";
			exit(0);
			break;
	}
	
	return 0;
}