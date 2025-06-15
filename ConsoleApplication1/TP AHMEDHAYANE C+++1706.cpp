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
		: std::runtime_error("Plus de produit en stock à bientot :" + nomProduit), produit(nomProduit), quantite(qte) {}

	std::string getProduit() const {return produit;}
	int getQuantite() const {return quantite;}

};
// Creation de la classe d'exception pour argument invalide
class ErreurArgumentInvalide : public std::invalid_argument {
public:
	ErreurArgumentInvalide(const std::string& message)
		: std::invalid_argument("Erreur : " + message) {}
};

//classe abstraite produit
class Produit {
protected:
	std::string nomProduit;
	double prixBase;

// constructeur
public:                  
	Produit(std::string nom, double prix) 
		: nomProduit(nom), prixBase(prix) {
	}

	std::string getNomproduit() const { return nomProduit; }; //accesseur
	double getPrixBase() const { return prixBase; };

	virtual void afficherDetailsProduit() const = 0; // metho virtuel
	virtual double calculerPrixTTC() const = 0;
	virtual void setStock(int nouveauStock) = 0;

	virtual ~Produit() = default;
};


// classe jeu video 
class JeuVideo : public Produit {
private:
	std::string genre;
	int stock;

public : 
	JeuVideo(std::string titre, std::string genre, double prix, int stock)
		: Produit(titre, prix), genre(genre) {

		 setStock(stock);

	  }

	//accesseur
	std::string getGenre() const {return genre;}
	int getStock() const {return stock;}


	//mutateurs
	void setPrix(double nouveauPrix) {
		if (nouveauPrix < 0) {
			std::cout << "Erreur, le prix est negatif !" << std::endl;
		}
		prixBase = nouveauPrix;
	}


	void setStock(int nouveauStock) override {
		if (nouveauStock < 0) {
			std::cout << "Erreur, le produit est en rupture de stock" << std::endl;
		}
		stock = nouveauStock;
	}

	// affichage des infos sur le JV
	void afficherInfos() const {
		std::cout << "Titre : " << nomProduit
			      << "Genre : " << genre
			      << "Prix :  " << prixBase << "€"
	       		  << "Prix TTC : " << calculerPrixTTC() << "€"
			      << "Stock :" << stock << std::endl;
	}

	double calculerPrixTTC() const override {
		return prixBase * 1.2;
	}
};

// classe console
class Console : public Produit {
private:
	std::string nomConsole;
	int stock;

public:
	Console(std::string nomConsole, double prix, int stock) { // constructeur cons
		setPrix(prix);
		setStock(stock);
	}

	std::string getNomConsole() const { return nomConsole; }
	double getPrix() const { return prix; }
	int getStock() const { return stock; }

	//mutateurs
	void setPrix(double nouveauPrix) {
		if (nouveauPrix < 0) {
			throw ErreurArgumentInvalide("le prix est negatif !");
		} else {
		   prix = nouveauPrix;
		}
	}

	void setStock(int nouveauStock) {
		if (nouveauStock < 0) {
			throw ErreurArgumentInvalide("le produit est en rupture de stock");
		} else {
			stock = nouveauStock;
		}
	}
	//  affichage des infos sur la console

	void afficherInfos() const {
		std::cout << "Console :" << nomConsole
			      << "Prix :" << prix << "€"
			      << "Stock :" << stock << std::endl;
	}
};




