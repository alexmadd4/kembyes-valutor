#include <iostream>
#include <map>

using namespace std;

map<pair<string, string>, double> exchangeRates;

double getExchangeRate(string fromCurrency, string toCurrency) {
    if (exchangeRates.count({fromCurrency, toCurrency})) {
        return exchangeRates[{fromCurrency, toCurrency}];
    }

    cout << "Shkruani kursin e kembimit nga " << fromCurrency << " ne " << toCurrency << ": ";
    double rate;
    cin >> rate;
    exchangeRates[{fromCurrency, toCurrency}] = rate;
    return rate;
}

int main() {
    cout << "Mire se erdhet ne kembyesin valutor!\n";

    while (true) {
        cout << "Shkruani valuten qe deshironi te kembeni (USD, EUR, ALL): ";
        string fromCurrency;
        cin >> fromCurrency;

        cout << "Shkruani valunten ne te cilen deshironi ta kembeni (USD, EUR, ALL): ";
        string toCurrency;
        cin >> toCurrency;

        if ((fromCurrency != "USD" && fromCurrency != "EUR" && fromCurrency != "ALL") ||
            (toCurrency != "USD" && toCurrency != "EUR" && toCurrency != "ALL")) {
            cout << "Valuta nuk ekziston. Opsionet e sakta jane (USD, EUR, ALL)\n";
            cout << "Opsionet e mundshme per kembim jane: USD ne EUR, USD ne ALL, EUR ne USD, EUR ne ALL, ALL ne USD, ALL ne EUR\n";
            continue;
        }

        cout << "Shkruaj shumen te cilen deshiron ta kembesh: ";
        double amount;
        cin >> amount;

        double exchangeRate = getExchangeRate(fromCurrency, toCurrency);
        cout << amount << " " << fromCurrency << " = " << amount * exchangeRate << " " << toCurrency << endl;

        cout << "A deshiron te kembesh akoma? (po/jo): ";
        string answer;
        cin >> answer;
        if (answer != "po") {
            break;
        }
    }

    cout << "Faleminderit qe perdoret kembimin valutor. Kalofshi nje dite sa me te mire!\n";
    return 0;
}

