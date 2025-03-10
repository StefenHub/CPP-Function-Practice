#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <cmath> 
using namespace std;

//---------------------Enumeration------------------------------------
enum ConversionType {
      USD_TO_EUR = 1,
      USD_TO_KHR,
      USD_TO_JPY,
      EUR_TO_USD,
      EUR_TO_KHR,
      EUR_TO_JPY,
      JPY_TO_USD,
      JPY_TO_EUR,
      JPY_TO_KHR,
      KHR_TO_USD,
      KHR_TO_EUR,
      KHR_TO_GBP,
      KHR_TO_JPY
  };

// ------------------------- Prototype -------------------------
  void printLogo();
  void currencyMenu();
  void numberCalculationMenu();
  void menu();
  void currencyConverter();
  void numberCalculation();
  void calculationNum1ToN();
  void process();

  double getRate(ConversionType type) {
      switch(type) {
          case USD_TO_EUR: return 0.92;
          case USD_TO_KHR: return 4100.0;
          case USD_TO_JPY: return 151.0;
          case EUR_TO_USD: return 1.09;
          case EUR_TO_KHR: return 4450.0;
          case EUR_TO_JPY: return 164.0;
          case JPY_TO_USD: return 0.0066;
          case JPY_TO_EUR: return 0.0061;
          case JPY_TO_KHR: return 27.1;
          case KHR_TO_USD: return 0.00024;
          case KHR_TO_EUR: return 0.00023;
          case KHR_TO_GBP: return 0.00018;
          case KHR_TO_JPY: return 0.037;
          default: return 1.0; 
      }
  }
  string getTargetCurrency(ConversionType type) {
    switch(type) {
        case USD_TO_EUR: return "EUR";
        case USD_TO_KHR: return "KHR";
        case USD_TO_JPY: return "JPY";
        case EUR_TO_USD: return "USD";
        case EUR_TO_KHR: return "KHR";
        case EUR_TO_JPY: return "JPY";
        case JPY_TO_USD: return "USD";
        case JPY_TO_EUR: return "EUR";
        case JPY_TO_KHR: return "KHR";
        case KHR_TO_USD: return "USD";
        case KHR_TO_EUR: return "EUR";
        case KHR_TO_GBP: return "GBP";
        case KHR_TO_JPY: return "JPY";
        default: return "";
    }
}

string getSourceSymbol(ConversionType type) {
    switch(type) {
        case USD_TO_EUR:
        case USD_TO_KHR:
        case USD_TO_JPY:
            return "$";
        case EUR_TO_USD:
        case EUR_TO_KHR:
        case EUR_TO_JPY:
            return "€";
        case JPY_TO_USD:
        case JPY_TO_EUR:
        case JPY_TO_KHR:
            return "¥";
        case KHR_TO_USD:
        case KHR_TO_EUR:
        case KHR_TO_GBP:
        case KHR_TO_JPY:
            return "៛";
        default: return "";
    }
}

// ------------------------- Main Function -------------------------
int main(){
      system("cls");
      printLogo();
      process();

      return 0;
}

// ----------------------------------------------------------------

void printLogo() {
      HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
      fstream file("logo.txt");  
      string line;
          
      while (getline(file, line)) {
          SetConsoleTextAttribute(consoleColor, 4);
          cout << right << "\t\t" << line << endl;  
          Sleep(120);
      }
  }
  void currencyMenu(){
      cout << "-----------< Currency Converter Menu >------------" << endl;
      cout << "[1]. USD to EUR" << endl;
      cout << "[2]. USD to KHR" << endl;
      cout << "[3]. USD to JPY" << endl;
      cout << "[4]. EUR to USD" << endl;
      cout << "[5]. EUR to KHR" << endl;
      cout << "[6]. EUR to JPY" << endl;
      cout << "[7]. JPY to USD" << endl;
      cout << "[8]. JPY to EUR" << endl;
      cout << "[9]. JPY to KHR" << endl;
      cout << "[10]. KHR to USD" << endl;
      cout << "[11]. KHR to EUR" << endl;
      cout << "[12]. KHR to GBP" << endl;
      cout << "[13]. KHR to JPY" << endl;
      cout << "[0]. Exit" << endl;
      cout << "--------------------------------------------------------" << endl;
}

void numberCalculationMenu(){
cout << "----------------------------------" << endl;
cout << "[+]. Addition" << endl;
cout << "[-]. Subtraction" << endl;
cout << "[x]. Multiplication" << endl;
cout << "[/]. Division" << endl;
cout << "[0]. Exit" << endl;
cout << "----------------------------------" << endl;
}

void menu(){
cout << "----------------------------------" << endl;
cout << "[1]. Currency Converter" << endl;
cout << "[2]. Number Calculation" << endl;
cout << "[3]. Calculation Num 1 -> n" << endl;
cout << "[0]. Exit" << endl;
cout << "----------------------------------" << endl;
}

void calculation1ToNMenu(){
cout << "------------<< Calculation Num 1 -> n! Menu >>-----------" << endl;
cout << "[+]. Sum 1 -> n" << endl;
cout << "[-]. Subtracting 1 -> n" << endl;
cout << "[x]. Multiplying 1 -> n" << endl;
cout << "[/]. Deviding 1 -> n" << endl;
cout << "[0]. Exit" << endl;
cout << "--------------------------------------------------------" << endl;
}

void currencyConverter(){
    int choice;
    double amount;
    system("cls");
    while(true) {
        currencyMenu();
        cout << "Enter your choice (0-13): ";
        cin >> choice;
        system("cls");
        if(choice == 0) break;
        
        if(choice < 1 || choice > 13) {
            cout << "Invalid choice! Try again." << endl;
            continue;
        }

        cout << "Enter amount to convert: ";
        cin >> amount;

        ConversionType type = static_cast<ConversionType>(choice);
        double rate = getRate(type);
        string sourceSymbol = getSourceSymbol(type);
        string targetCurrency = getTargetCurrency(type);
        double result = amount * rate;

        cout << "\nYour total amount " << amount << " " << sourceSymbol
             << " is " << result << " " << targetCurrency << endl;
        cout << "-----------------------------" << endl;
    }
  
}

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { 
    return (b != 0.0) ? (a / b) : NAN;
}
void numberCalculation(){
      char choice;
    double num1, num2, result;
    system("cls");

    do {
        numberCalculationMenu();
        cout << "Enter choice (0 to exit): ";
        cin >> choice;

        if (choice == '0') break;

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        cout << fixed << setprecision(2); 

        switch(choice) {
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case 'x':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                result = divide(num1, num2);
                cout << (isnan(result) ? "Error: Division by zero!" 
                                      : "Result: " + to_string(result)) 
                     << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
        cout << "Press any key to continue..." << endl;
        getch();
    } while (true);
}
  
  int getPositiveInteger() {
      int n;
      while (true) {
          cout << "Enter n (positive integer): ";
          if (cin >> n && n > 0) break;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input. Please enter a positive integer." << endl;
      }
      return n;
  }
  
  int calculateSum(int n) {
      return n * (n + 1) / 2;
  }
  
  int calculateSubtraction(int n) {
      int result = 1;
      for (int i = 2; i <= n; ++i) result -= i;
      return result;
  }
  
  long long calculateProduct(int n) {
      long long product = 1;
      for (int i = 1; i <= n; ++i) product *= i;
      return product;
  }
  
  double calculateDivision(int n) {
      double result = 1.0;
      for (int i = 2; i <= n; ++i) result /= i;
      return result;
  }
  
  void calculationNum1ToN(){
      char choice;
      system("cls");
    do {
        calculation1ToNMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '0') break;

        int n = getPositiveInteger();
        
        cout << fixed << setprecision(6);
        
        switch(choice) {
            case '+':
                cout << "Sum(1.." << n << ") = " << calculateSum(n) << endl;
                break;
            case '-':
                cout << "Subtract(1.." << n << ") = " << calculateSubtraction(n) << endl;
                break;
            case 'x':
                cout << "Product(1.." << n << ") = " << calculateProduct(n) << endl;
                break;
            case '/':
                cout << "Divide(1.." << n << ") = " << calculateDivision(n) << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
        cout << "Press any key to continue..." << endl;
        getch();
    } while (true);
}
void process(){
      while (true) {
            menu();
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                  case 1:
                        currencyConverter();
                        break;
                  case 2:
                        numberCalculation();
                        break;
                  case 3:
                        calculationNum1ToN();
                        break;
                  case 0:
                        cout << "Exiting the program..." << endl;
                        exit(0);
                  default:
                        cout << "Invalid choice. Please try again." << endl;

        }
        cout << "Press any key to continue..." << endl;
        getch();
      }

}