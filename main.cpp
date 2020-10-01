#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;

class complex
{
private:
	float real;
	float image;
	
public:
	complex();
	~complex();
	void set_real(float number);
	void set_image(float number);
	float get_real()const;
	float get_image()const;
	
	
	complex operator+(complex com)
	{
		complex temp;
		temp.real = real + com.real;
		temp.image = image + com.image;
		return temp;
	}
	complex operator-(complex com)
	{
		complex temp;
		temp.real = real - com.real;
		temp.image = image - com.image;
		return temp;
	}
	complex operator*(complex com)
	{
		complex temp;
		temp.real = com.real*real - com.image*image;
		temp.image = real*com.image + image*com.real;
		return temp;
	}
	complex operator/(complex com)
	{
		complex temp;
		temp.real = (real*com.real + image*com.image) / (com.real*com.real + com.image*com.image);
		temp.image = (image*com.real - real*com.image) / (com.real*com.real + com.image*com.image);
		return temp;
	}
	friend ostream&operator<< (ostream&os, complex & com);
};

complex::complex()
{
	real = 0;
	image = 0;
}
complex::~complex() {}

void complex::set_real(float number)
{
	real = number;
}
void complex::set_image(float number)
{
	image = number;
}

float complex::get_real()const
{
	return real;
}
float complex::get_image()const
{
	return image;
}

ostream&operator<< (ostream&os, complex & com)
{
	if (fabs(com.image) == 0)
		os << com.real << endl;
	else if (fabs(com.real) == 0)
		os << com.image << "i" << endl;
	else if (com.image > 0)
		os << com.real << " + " << com.image << "i" << endl;
	else
		os << com.real << com.image << "i" << endl;
	return os;
}
void addition()
{
	complex z1, z2;
	complex result;
	float n1, n2, n3, n4;
	cout << "First input: ";
	cin >> n1 >> n2;
	z1.set_real(n1);
	z1.set_image(n2);
	cout << "Second Input: ";
	cin >> n3 >> n4;
	z2.set_real(n3);
	z2.set_image(n4);
	
	result = z1 + z2;
	cout << result;

}

void subtraction()
{
	complex z1, z2;
	complex result;
	float n1, n2, n3, n4;
	cout << "First input: ";
	cin >> n1 >> n2;
	z1.set_real(n1);
	z1.set_image(n2);
	cout << "Second Input: ";
	cin >> n3 >> n4;
	z2.set_real(n3);
	z2.set_image(n4);

	result = z1 - z2;
	cout << result;
}

void multiplication()
{
	complex z1, z2;
	complex result;
	float n1, n2, n3, n4;
	cout << "First input: ";
	cin >> n1 >> n2;
	z1.set_real(n1);
	z1.set_image(n2);
	cout << "Second Input: ";
	cin >> n3 >> n4;
	z2.set_real(n3);
	z2.set_image(n4);

	result = z1 * z2;
	cout << result;
}

void division()
{
	complex z1, z2;
	complex result;
	float n1, n2, n3, n4;
	
	cout << "First input: ";
	cin >> n1 >> n2;
	z1.set_real(n1);
	z1.set_image(n2);
	cout << "Second Input: ";
	cin >> n3 >> n4;
	if (n3 == 0 && n4 == 0)
	{
		cout << "Error" << endl;
	}
	else
	{
		z2.set_real(n3);
		z2.set_image(n4);

		result = z1 / z2;
		cout << result;
	}
	
	
}

void add(float n1, float n2, float n3, float n4)
{
	complex z1, z2, result;
	z1.set_real(n1);
	z1.set_image(n2);
	z2.set_real(n3);
	z2.set_image(n4);
	result = z1 + z2;
	cout << result;
}
void sub(float n1, float n2, float n3, float n4)
{
	complex z1, z2, result;
	z1.set_real(n1);
	z1.set_image(n2);
	z2.set_real(n3);
	z2.set_image(n4);
	result = z1 - z2;
	cout << result;
}
void mul(float n1, float n2, float n3, float n4)
{
	complex z1, z2, result;
	z1.set_real(n1);
	z1.set_image(n2);
	z2.set_real(n3);
	z2.set_image(n4);
	result = z1 * z2;
	cout << result;
}
void div(float n1, float n2, float n3, float n4)
{
	complex z1, z2, result;
	z1.set_real(n1);
	z1.set_image(n2);
	z2.set_real(n3);
	z2.set_image(n4);
	result = z1 / z2;
	cout << result;
}

void read_file()
{
	ifstream inData;
	ofstream outData;
	float t;
	float number[4];
	float number2[4];
	float number3[4];
	float number4[4];
	string temp;
	string string;
	
	int index = 0;
	int count = 0;

	inData.open("test.txt");
	if (inData.fail())
	{
		cout << "Cannot open input file " << endl;
	}


	while (!inData.eof())
	{
		getline(inData, string);
		int i = 0;

		for (index = 0; index < string.size(); index++)
		{
			if (string[index] == 'A' || string[index] == 'a')
			{
				for (int j = index; j < string.size() - 1; j++)
				{
					if (string[j] == ' ')
					{
						do
						{
							count++;
						} while ((string[j + count] != ' ') && ((j + count + 1) != string.size()));
						temp = string.substr(j + 1, count);
						t = atof(temp.c_str());
						number[i] = t;
						cout << number[i] << " ";
						i++;
						count = 0;

					}
				}
				cout << endl << "A ";
				add(number[0], number[1], number[2], number[3]);
				cout << endl;
				
			}
			else if (string[index] == 'S' || string[index] == 's')
			{
				for (int j = index; j < string.size() - 1; j++)
				{
					if (string[j] == ' ')
					{
						do
						{
							count++;
						} while ((string[j + count] != ' ') && ((j + count + 1) != string.size()));

						temp = string.substr(j + 1, count);
						t = atof(temp.c_str());
						number2[i] = t;;
						cout << number2[i] << " ";
						i++;
						count = 0;

					}
				}
				cout << endl << "S ";
				sub(number2[0], number2[1], number2[2], number2[3]);
				cout << endl;

			}
			else if (string[index] == 'M' || string[index] == 'm')
			{
				for (int j = index; j < string.size() - 1; j++)
				{
					if (string[j] == ' ')
					{
						do
						{
							count++;
						} while ((string[j + count] != ' ') && ((j + count + 1) != string.size()));

						temp = string.substr(j + 1, count);
						t = atof(temp.c_str());
						number3[i] = t;
						cout << number3[i] << " ";
						i++;
						count = 0;

					}
				}
				cout << endl << "M ";
				mul(number3[0], number3[1], number3[2], number3[3]);
				cout << endl;

			}
			else if (string[index] == 'D' || string[index] == 'd')
			{
				for (int j = index; j < string.size() - 1; j++)
				{
					if (string[j] == ' ')
					{
						do
						{
							count++;
						} while ((string[j + count] != ' ') && ((j + count + 1) != string.size()));
						 
						temp = string.substr(j + 1, count);
						t = atof(temp.c_str());
						number4[i] = t;
						cout << number4[i] << " ";
						i++;
						count = 0;

					}
				}
				cout << endl << "D ";
				if (number4[2] == 0 && number4[3] == 0)
					cout << "Error" << endl;
				else
				{
					div(number4[0], number4[1], number4[2], number4[3]);
					cout << endl;
				}
			

			}
			

		}
	}
		outData.open("output.txt");
		inData.close();
		outData.close();
	
}

void Interactive_mode()
{
	char letter;
	cout << "A, S, M, or D which indicates which operation"
		<< "(addition, subtraction, multiplication or division)" << endl;
	cout << endl;
	do
	{
		cout << "Enter exp: ";
		cin >> letter;
		if (letter == 'A' || letter == 'a')
		{
			addition();
		}
		else if (letter == 'S' || letter == 's')
		{
			subtraction();
		}
		else if (letter == 'M' || letter == 'm')
		{
			multiplication();
		}
		else if (letter == 'D' || letter == 'd')
		{
			division();
		}
		else if (letter == 'Q' || letter == 'q')
		{
			break;
		}
		else
		{
			cout << "Wrong input!!!" << endl;
		}
	} while (letter);
	
}

void Batch_mode()
{
	
	read_file();
	cout << endl;
}


int main()
{
	
	char letter;
	do
	{
		cout << "Choose your option (I or i for Interactive mode; B or b for Batch mode) and Q or q should quit the program: ";
		cin >> letter;
		if (letter == 'I' || letter == 'i')
		{
			Interactive_mode();
		}
		else if (letter == 'B' || letter == 'b')
		{
			Batch_mode();
		}
		else if (letter == 'Q' || letter == 'q')
		{
			break;
		}
		else
		{
			cout << "Wrong input!!!" << endl;
		}
		

	} while (letter);
	
	return 0;

}