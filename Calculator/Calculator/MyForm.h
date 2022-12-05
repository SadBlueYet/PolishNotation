#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <math.h>
#include <string.h>
#include <string>
#define PI 3.14159265
namespace Calculator {
	char* userInput(char* bufptr);
	char* exitString(char* bufptr);
	void mathOperations(char* a);
	char* trigonometry(double value, int& count, int& counter, char* exitString);
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(156, 266);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"=";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(14, 222);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(42, 38);
			this->button2->TabIndex = 1;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(10, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(231, 38);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(62, 222);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(42, 38);
			this->button3->TabIndex = 3;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(110, 222);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(42, 38);
			this->button4->TabIndex = 4;
			this->button4->Text = L"3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(14, 178);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(42, 38);
			this->button5->TabIndex = 5;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(62, 178);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(42, 38);
			this->button6->TabIndex = 6;
			this->button6->Text = L"5";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(110, 178);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(42, 38);
			this->button7->TabIndex = 7;
			this->button7->Text = L"6";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(14, 134);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(42, 38);
			this->button8->TabIndex = 8;
			this->button8->Text = L"7";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(62, 134);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(42, 38);
			this->button9->TabIndex = 9;
			this->button9->Text = L"8";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(110, 134);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(42, 38);
			this->button10->TabIndex = 10;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(13, 266);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(138, 38);
			this->button11->TabIndex = 11;
			this->button11->Text = L"0";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(156, 222);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(42, 38);
			this->button12->TabIndex = 12;
			this->button12->Text = L".";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(253, 312);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			char* buffer = (char*)malloc(1024 * sizeof(char));
			int counter = 0;
			String^ s = textBox1->Text;
			s += " ";
			while (s[counter] != ' ') {
				buffer[counter] = s[counter];
				counter++;
			}
			userInput(buffer);
	}
	private:
		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			
	}
	private:
		System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private:
		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "2";
	}
	private:
		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "3";
	}
	private:
		System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "4";
	}
	private:
		System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "5";
	}
	private:
		System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "6";
	}
	private:
		System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "7";
	}
	private:
		System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "8";
	}
	private:
		System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += "9";
	}
     private:
		 System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		 textBox1->Text += "0";
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text += ".";
	}

	   

};
class Stack {
public:
	std::stack <char> operators;
	int counter = 0;
	void stackPush(char oper) {
		operators.push(oper);
	}
	char* stackPopAndPush(char oper) {
		char* stringOfoperators = (char*)malloc(1024 * sizeof(char));
		counter = 0;
		do {
			if (operators.size() == 0) break;
			if ((oper == '+' || oper == '-') && operators.top() == '(') break;
			if ((oper == '*' || oper == '/') && (operators.top() == '+' || operators.top() == '-' || operators.top() == '(' || operators.size() == 0)) break;
			if (oper == '^' && operators.size() == 0) break;
			if (oper == ')' && operators.top() == '(') {
				operators.pop();
				break;
			}
			stringOfoperators[counter] = operators.top();
			stringOfoperators[counter + 1] = ' ';
			counter += 2;
			operators.pop();
			if (counter % 1024 == 0)
				stringOfoperators = (char*)realloc(stringOfoperators, 1024 * (counter / 1024 + 1) * sizeof(char));
		} while (true);
		if (oper != ')') operators.push(oper);
		stringOfoperators[counter] = '\0';
		return stringOfoperators;
	}
};
char* userInput(char* bufptr) {
	char* buffer = (char*)malloc(1024 * sizeof(char));
	buffer = bufptr;
	return exitString(buffer);
}
char* exitString(char* bufptr) {
	Stack stack;
	double value;
	std::string num;
	char* p = bufptr;
	char* exitString = (char*)malloc(1024 * sizeof(char));
	char* operatr = (char*)malloc(1024 * sizeof(char));
	int counter = 0;
	do {
		if (isdigit(*p)) {
			exitString[counter] = *p;
			p++;
			counter++;
			if (isdigit(*p) || (*p == '.' || *p == ',')) {
				do {
					if (*p == '.' || *p == ',') {
						exitString[counter] = '.';
						p++;
						counter++;
					}
					exitString[counter] = *p;
					p++;
					counter++;

				} while (isdigit(*p) || (*p == '.' || *p == ','));

			}
			exitString[counter] = ' ';
			counter++;
		}

		else {
			if ((stack.operators.empty() || *p == '(') && *p != 's') {
				stack.stackPush(*p);
				p++;
			}
			else {
				int count = 0;
				if (*p == ')') {
					operatr = stack.stackPopAndPush(*p);
					if (strlen(operatr) % 1024 == 0)
						operatr = (char*)realloc(operatr, 1024 * (strlen(operatr) / 1024 + 1) * sizeof(char));
					exitString[counter] = '\0';
					exitString = strcat(exitString, operatr);
					counter += stack.counter;
					p++;
					continue;
				}
				else if (*p == 's' || *p == 'S') {
					p++;
					if (*p == 'q' || *p == 'Q') {
						while (!isdigit(*p)) {
							p++;
						}
						value = atoi(p);
						value = sqrt(value);
						exitString = trigonometry(value, count, counter, exitString);
						continue;
					}
					if (*p == 'i' || *p == 'I') {
						while (!isdigit(*p)) {
							p++;
						}
						value = atoi(p);
						value = sin(value * PI / 180);
						exitString = trigonometry(value, count, counter, exitString);
						continue;
					}
				}
				else if (*p == 'c' || *p == 'C') {
					p++;
					if (*p == 'o' || *p == 'O') {
						while (!isdigit(*p)) {
							p++;
						}
						value = atoi(p);
						value = cos(value * PI / 180);
						exitString = trigonometry(value, count, counter, exitString);
						continue;
					}
					if (*p == 't' || *p == 'T') {
						p++;
						if (*p == 'o' || *p == 'O') {
							while (!isdigit(*p)) {
								p++;
							}
							value = atoi(p);
							value = 1 / tan(value * PI / 180);
							num = std::to_string(value);
							exitString = trigonometry(value, count, counter, exitString);
							continue;
						}
					}
				}
				else if (*p == 't' || *p == 'T') {
					while (!isdigit(*p)) {
						p++;
					}
					value = atoi(p);
					value = tan(value * PI / 180);
					exitString = trigonometry(value, count, counter, exitString);
					continue;
				}
				else {
					operatr = stack.stackPopAndPush(*p);
					if (strlen(operatr) % 1024 == 0)
						operatr = (char*)realloc(operatr, 1024 * (strlen(operatr) / 1024 + 1) * sizeof(char));
					exitString[counter] = '\0';
					exitString = strcat(exitString, operatr);
					counter += stack.counter;
					p++;
					continue;
				}
				stack.stackPush(*p);
				p++;
			}
		}
		if (counter % 1024 == 0)
			exitString = (char*)realloc(exitString, 1024 * (counter / 1024 + 1) * sizeof(char));
	} while (*p != '\0');

	if (stack.operators.size() != 0) {
		do {
			exitString[counter] = stack.operators.top();
			exitString[counter + 1] = ' ';
			stack.operators.pop();
			counter += 2;
			if (counter % 1024 == 0)
				exitString = (char*)realloc(exitString, 1024 * (counter / 1024 + 1) * sizeof(char));
		} while (stack.operators.size() != 0);
	}
	exitString[counter] = '\0';
	return exitString;
}

void mathOperations(char* a) {
	std::istringstream str(a);
	std::stack<double> numbers;
	double value;
	char oper;
	double right, left;
	while (!str.eof())
	{
		while (str >> value) {
			numbers.push(value);
		}
		if (!str.eof()) {
			str.clear();
			str.unget();
			str >> oper;
			if (numbers.size() < 2) {
				std::cout << "corrupt oper. order" << std::endl;
				return;
			}
			right = numbers.top();
			numbers.pop();
			left = numbers.top();
			numbers.pop();
			if (oper == '+') numbers.push(left + right);
			if (oper == '-') numbers.push(left - right);
			if (oper == '*') numbers.push(left * right);
			if (oper == '/') numbers.push(left / right);
			if (oper == '^') numbers.push(pow(left, right));
		}
	}
	if (numbers.size() != 1) {
		std::cout << "stack corrupted" << std::endl;
		return;
	}
	std::cout << "result value is " << numbers.top() << std::endl;
	return;
}
char* trigonometry(double value, int& count, int& counter, char* exitString) {
	std::string num;
	num = std::to_string(value);
	while (num[count] != '\0') {
		exitString[counter] = num[count];
		counter++; count++;
	}
	exitString[counter] = ' ';
	return exitString;
}
}
