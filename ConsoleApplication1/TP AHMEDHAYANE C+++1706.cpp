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

// classe jeu video 
class JeuVideo {
private:
	std::string titre;
	std::string genre;
	double prix;
	int stock;

public:
	JeuVideo(std::string titre, std::string genre, double prix, int stock) { // constructeur jeuvideo
		 setPrix(prix);
		 setStock(stock);

	}

	//accesseur
	std::string getTitre() const { return titre; };
	std::string getGenre() const {return genre;}
	double getPrix() const {return prix;}
	int getStock() const {return stock;}


	//mutateurs
	void setPrix(double nouveauPrix) {
		if (nouveauPrix < 0) {
			std::cout << "Erreur, le prix est negatif !" << std::endl;
		}
		else {
			prix = nouveauPrix;
		}
	}

	void setStock(int nouveauStock) {
		if (nouveauStock < 0) {
			std::cout << " Erreur, le produit est en rupture de stock " << std::endl;
		}
		else {
			stock = nouveauStock;
		}
	}

	// affichage des infos sur le JV
	void afficherInfos() const {
		std::cout << "Titre : " << titre
			<< "Genre : " << genre
			<< "Prix :  " << prix << "€"
			<< "Stock :" << stock << std::endl;
	}
};

// classe console
class Console {
private:
	std::string nomConsole;
	double prix;
	int stock;

public:
	Console(std::string nomConsole, double prix, int stock) { // constructeur cons
		 setPrix(prix);
		 setStock(stock);
	}

	std::string getNomConsole() const {return nomConsole;}
	double getPrix() const {return prix;}
	int getStock() const {return stock;}

	//mutateurs
	void setPrix(double nouveauPrix) {
		if (nouveauPrix < 0) {
			std::cout << "Erreur, le prix est negatif !" << std::endl;
		}
		else {
			prix = nouveauPrix;
		}
	}

	void setStock(int nouveauStock) {
		if (nouveauStock < 0) {
			std::cout << " Erreur, le produit est en rupture de stock " << std::endl;
		}
		else {
			stock = nouveauStock;
		}
	}
	//  affichage des infos sur la console

	void afficherInfos() const {
		std::cout << "Console :" << nomConsole
			<< "Prix :" << prix << "€"
			<< "Stock :" << stock << std::endl;
	}

//classe abstraite produit
class Produit {
protected:
	std::string nomProduit;
	double prixBase;

// constructeur
	Produit(std::string nom, double prix) {
		nomProduit = nom;
		prixBase = prix;
	}

//accesseur

public :
	std::string getNomproduit() const { return nomProduit; };
    double getPrixBase() const {return prixBase;};

	virtual void afficherDetailsProduits() const = 0;


