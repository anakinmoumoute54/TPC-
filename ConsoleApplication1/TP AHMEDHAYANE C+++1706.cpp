#include <iostream>
#include <string>
#include <stdexcept>

// Creation de la classe d'exception pour stock insuffisant
class ErreurStockInsuffisant : public std::runtime_error {
private:
	std::string produit;
	int quantite;

public:
	ErreurStockInsuffisant(const std::string& nomProduit, int qte)
		: std::runtime_error("Plus de produit en stock pour bientot :" + nomProduit), produit(nomProduit), quantite(qte) {}

	std::string getProduit() const {
		return produit;
	}

	int getQuantite() const {
		return quantite;
	}
};
// Creation de la classe d'exception pour argument invalide
class ErreurArgumentInvalide : public std::invalid_argument {
public:
	ErreurArgumentInvalide(const std::string& message)
		: std::invalid_argument("Erreur : " + message) {}
};

class JeuVideo {
private:
	std::string titre;
	std::string genre;
	double prix;
	int stock;

public:

	class Console {
		std::string nomConsole;
		double prix;
		int stock;
