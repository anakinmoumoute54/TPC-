#include <iostream>
#include <string>
#include <stdexcept>

// creation de la classe d'exception pour stock insuffisant
class ErreurStockInsuffisant : public std::runtime_error {
private:
	std::string produit;
	int quantite;

public:
	ErreurStockInsuffisant(const std::string& nomProduit, int qte)
		: std::runtime_error("Plus de produit en stock à bientot :" + nomProduit), produit(nomProduit), quantite(qte) {}

	std::string getTitreProduit() const {return produit;}
	int getQuantiteDemandee() const {return quantite;}


};
// creation de la classe d'exception pour argument invalide
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
protected:                  
	Produit(std::string nom, double prix) 
		: nomProduit(nom), prixBase(prix) {
	}

public:
	std::string getNomProduit() const { return nomProduit; }; //accesseur
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

public:
	JeuVideo(std::string titre, std::string genre, double prix, int stock)
		: Produit(titre, prix), genre(genre) {
		setStock(stock);
	}

	// accesseurs
	std::string getGenre() const { return genre; }
	int getStock() const  { return stock; }

	// mutateurs
	void setStock(int nouveauStock) {
		if (nouveauStock < 0) {
			std::cout << "Erreur, le produit est en rupture de stock" << nouveauStock << std::endl;
		}
		else {
			stock = nouveauStock;
		}
	}

	void setPrix(double nouveauPrix) {
		if (nouveauPrix < 0) {
			std::cout << "Erreur, le prix est négatif : " << nouveauPrix << "€" << std::endl;
		}else {
			prixBase = nouveauPrix;
		}
	}

	double calculerPrixTTC() const  {
		return prixBase * 1.2;
	}

	// affichage des infos sur le JV
	void afficherDetailsProduit() const {
		std::cout << "Titre : " << getNomProduit() << std::endl;
		std::cout << "Genre : " << genre << std::endl;
		std::cout << "Prix : " << getPrixBase() << "€" << std::endl;
		std::cout << "Prix TTC : " << calculerPrixTTC() << "€" << std::endl;
		std::cout << "Stock : " << stock << std::endl;
	}

};
// classe console
class Console : public Produit {
private:
	int stock;

public:
	Console(std::string nom, double prix, int stock)
		: Produit(nom, prix) {
		setStock(stock);
	}

	// accesseurs
	int getStock() const { return stock; }

	// mutateurs
	void setStock(int nouveauStock) {
		if (nouveauStock < 0) {
			std::cout << "Erreur, le produit est en rupture de stock ! " << nouveauStock << std::endl;
		}
		else {
			stock = nouveauStock;
		}
	}
	void setPrix(double nouveauPrix) {
		if (nouveauPrix < 0) {
			std::cout << "Erreur, le prix est négatif : " << nouveauPrix << "€" << std::endl;
		}else {
		   prixBase = nouveauPrix;
		}
	}

	double calculerPrixTTC() const {
		return prixBase * 1.2;
	}

	// affichage des infos
	void afficherDetailsProduit() const {
		std::cout << "Nom Console : " << getNomProduit() << std::endl;
		std::cout << "Prix : " << getPrixBase() << "€" << std::endl;
		std::cout << "Prix TTC : " << calculerPrixTTC() << "€" << std::endl;
		std::cout << "Stock : " << stock << std::endl;
	}
  };

// surchage operateur classe pdt
std::ostream& operator <<(std::ostream& os, const Produit& produit){
	produit.afficherDetailsProduit();
	return os;
}


