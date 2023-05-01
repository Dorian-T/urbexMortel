#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"
#include "../building/Room.h"
#include "../building/Building.h"

enum Skin {
	batman = 0,
	coaraa = 2,
	daisy = 4,
	dora = 6,
	gadget = 8,
	lilith = 10,
	maestro = 12,
	pikmin = 14,
	tibouyou = 16,
	yumi = 18
};

/**
 * @brief Classe du joueur
 * 
 * @details classe héritée de Entity
 */
class Player : public Entity {
	private:

		/**
		 * @brief Choix du skin
		 */
		Skin skin;

		/**
		 * @brief Points de vie
		 */
		unsigned int hp;

		/**
		 * @brief Temps où le joueur est invincible après s'être pris un coup
		 */
		unsigned int timeInvincible;

		/**
		 * @brief bool vrai pour le personnage regarde à droite faux à gauche
		 * 
		 */
		bool orientation;

		/**
		 * @brief Vérifie si le déplacement vers le haut est possible
		 * 
		 * @details renvoie -1 si le déplacement est possible
		 * @details retourne -3 si on monte sur une trappe
		 * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
		 * 
		 * @param R 
		 * @param V
		 * @return int
		 */
		int isMovePossibleUp(const Room & R, const Vector2D & V) const;

		/**
		 * @brief Vérifie si le déplacement vers la gauche ou la droite est possible
		 * 
		 * @details retourne -1 si le déplacement est possible
		 * @details retourne -2 si le déplacement change de salle
		 * @details retourne -4 si on boit une potion
		 * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
		 * 
		 * @param R 
		 * @param V
		 * @return int
		 */
		int isMovePossibleSide(const Room & R, const Vector2D & V) const;

		/**
		 * @brief Vérifie si le déplacement vers le bas est possible
		 * 
		 * @details retourne -1 si le déplacement est possible
		 * @details retourne -4 si on boit une potion
		 * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
		 * 
		 * @param R 
		 * @param V
		 * @return int
		 */
		int isMovePossibleDown(const Room & R, const Vector2D & V) const;

		/**
		 * @brief Vérifie si le déplacement vers le bas est possible
		 * 
		 * @details retourne -1 si le déplacement est possible
		 * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
		 * 
		 * @param R
		 * @param V
		 * @return int
		 */
		int isMovePossibleGravity(const Room & R, const Vector2D & V) const;

		/**
		 * @brief Ajoute du temps avant l'empoisonnement
		 * 
		 * @param B
		 */
		void drinkPotion(Building & B);

	public:

		/**
		 * @brief Constructeur paramétré
		 * 
		 * @param p
         * @param s
         * @param health
		 */
		Player(const Vector2D & p, Skin s, unsigned int health);

		/**
		 * @brief Accesseur du skin
		 * 
		 * @return Skin
		 */
		Skin getSkin() const;

		/**
		 * @brief Modificateur du skin
		 * 
		 * @param S
		 */
		void setSkin(Skin S);

		/**
		 * @brief Accesseur de hp
		 * 
		 * @return unsigned int 
		 */
		unsigned int getHp();

		/**
		 * @brief Baisse les points de vie
		 * 
		 * @details si le joueur est invincible, les points de vie ne sont pas baissés
		 * @details renvoie faux si le joueur est mort
		 * 
		 * @param h
		 * @return bool
		 */
		bool decreaseHp(unsigned int h);

		/**
		 * @brief Accesseur de timeInvincible
		 * 
		 * @return unsigned int
		 */
		unsigned int getTimeInvincible();

		/**
		 * @brief Baisse le temps d'invincibilité
		 */
		void decreaseTimeInvincible();

		/**
		 * @brief Accesseur de orientation
		 * 
		 * @return bool
		 */
		bool getOrientation();

		/**
		 * @brief Déplacement vers le haut (saut)
		 * 
		 * @param B
		 */
		void up(Building & B);

		/**
		 * @brief Déplacement vers la droite et renvoie un bool si on a fini
		 * 
		 * @param B
		 */
		bool right(Building & B);

		/**
		 * @brief Déplacement vers le bas
		 * 
		 * @param B
		 */
		void down(Building & B);

		/**
		 * @brief Déplacement vers la gauche
		 * 
		 * @param B
		 */
		void left(Building & B);

		/**
		 * @brief Application de la gravité
		 * 
		 * @param R
		 */
		void gravity(const Room & R);

		/**
		 * @brief Renvoie si le joueur est sur un block ou non
		 * 
		 * @param R
		 * @return bool
		 */
		bool standingOnBlock(const Room & R) const;

		/**
		 * @brief action de block famtome 
		 * 
		 * @param R
		 */
		void StandingOnGhostBlock(Room & R);

		/**
		 * @brief Tests de non-regression
		 */
		void regressionTest();
};

#endif
