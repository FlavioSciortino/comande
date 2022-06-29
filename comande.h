#ifndef COMANDE_H
#define COMANDE_H
class comande {
	string cognome, pizza;
	int qta;
	double prezzo;
public:
	comande(string cognome, string pizza, int qta, double prezzo) : cognome(cognome), pizza(pizza), qta(qta), prezzo(prezzo) {}
	friend ostream &operator<<(ostream &os, comande & c) {
		os << "cognome = " << c.cognome << endl;
		os << "pizza = " << c.pizza << endl;
		os << "quantità = " << c.qta << endl;
		os << "prezzo = " << c.prezzo << endl;
		return os;
	}

	friend istream &operator>>(istream &is, comande & c) {
		string qta_str, prezzo_str;
		std::getline(is, g.cognome, ';');
		std::getline(is, g.pizza, ';');
		std::getline(is, qta_str, ';');
		std::getline(is, prezzo_str, '\n');
		c.qta = std::atoi(qta_str.c_str());
		c.prezzo = std::atof(prezzo_str.c_str());
		return is;
	}
};
#endif
	

	