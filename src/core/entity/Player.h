#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"
#include "../building/Room.h"
#include "../building/Building.h"

enum Skin {
    M,
    F
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
         * @brief savoir si il est entrain de tomber
         * 
         */
        bool isFailling;

        /**
         * @brief savoir si il est entrain de bouger
         * 
         */
        bool isMoving;

        /**
         * @brief savoir si il est entrain de sauter
         * 
         */
        bool isJumping;

        /**
         * @brief la direction du personnage, faux=gauche et vrai=droite
         * 
         */
        bool direction;

        /**
         * @brief Vérifie si le déplacement vers le haut est possible
         * 
         * @details renvoie -1 si le déplacement est possible
         * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
         * @details retourne -3 si on monte sur une trappe
         * 
         * @param position 
         * @param R 
         * @return int 
         */
        int isMovePossibleUp(const Vector2D & position, Room * R) const;

        /**
         * @brief Vérifie si le déplacement vers la gauche ou la droite est possible
         * 
         * @details retourne -1 si le déplacement est possible
         * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
         * 
         * @details retourne -2 si le déplacement change de salle
         * 
         * @param position 
         * @param R 
         * @return int 
         */
        int isMovePossibleSide(const Vector2D & position, Room * R) const;

        /**
         * @brief Vérifie si le déplacement vers le bas est possible
         * 
         * @details retourne -1 si le déplacement est possible
         * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
         * 
         * @param position 
         * @param R 
         * @return int 
         */
        int isMovePossibleDown(const Vector2D & position, Room * R) const;

        /**
         * @brief Vérifie si le déplacement vers le bas est possible
         * 
         * @details retourne -1 si le déplacement est possible
         * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
         * 
         * @param position 
         * @param R 
         * @return int 
         */
        int isMovePossibleGravity(const Vector2D & position, Room * R) const;

    public:
        /**
         * @brief Constructeur par défaut
         */
        Player();

        /**
         * @brief Constructeur paramétré
         * 
         * @param s
         * @param h
         */
        Player(const Vector2D & p, Skin s, unsigned int health);

        /**
         * @brief Baisse les points de vie
         * 
         * @details si le joueur est invincible, les points de vie ne sont pas baissés
         * @details renvoie faux si le joueur est mort
         * 
         * @param h
         * 
         * @return bool
         */
        bool decreaseHp(unsigned int h);

        /**
         * @brief Baisse le temps d'invincibilité
         */
        void decreaseTimeInvincible();

        /**
         * @brief Déplacement vers le haut (saut)
         * 
         * @param R
         */
        void up(Building * B);

        /**
         * @brief Déplacement vers la droite et renvoie un bool si on a fini
         * 
         * @param R 
         */
        bool right(Building * B);

        /**
         * @brief Déplacement vers le bas
         * 
         * @param R 
         */
        void down(Building * B);

        /**
         * @brief Déplacement vers la gauche
         * 
         * @param R 
         */
        void left(Building * B);

        /**
         * @brief Renvoie si le joueur est sur un block ou non
         * 
         * @param b 
         * @return bool
         */
        bool standingOnBlock(Building * b);

        /**
         * @brief Application de la gravité
         * 
         * @param R 
         */
        void gravity(Building * B);

        /**
         * @brief Accesseur de hp
         * 
         * @return unsigned int 
         */
        unsigned int getHp();

        /**
         * @brief Accesseur de timeInvincible
         * 
         * @return unsigned int 
         */
        unsigned int getTimeInvincible();

        /**
         * @brief Accesseur de isJumping
         * 
         * @return true 
         * @return false 
         */
        bool getIsJumping();

        /**
         * @brief Accesseur de isMoving
         * 
         * @return true 
         * @return false 
         */
        bool getIsMoving();

        /**
         * @brief Accessseur de IsJumping
         * 
         * @return true 
         * @return false 
         */
        bool getIsFailling();

        /**
         * @brief Accesseur de Direction
         * 
         * @return true 
         * @return false 
         */
        bool getDirection();

        /**
         * @brief Set the Direction object
         * 
         */
        void setDirection(bool D);

        /**
         * @brief Set the IsFailling object
         * 
         * @param F 
         */
        void setIsFailling(bool F);

        /**
         * @brief Set the IsJumping object
         * 
         * @param J 
         */
        void setIsJumping(bool J);

        /**
         * @brief Set the IsMoving object
         * 
         * @param M 
         */
        void setIsMoving(bool M);

        /**
         * @brief Test de non-regression
         */
        void regressionTest();
};

#endif
