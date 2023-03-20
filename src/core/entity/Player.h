#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"
#include "../building/Room.h"
#include "../building/Building.h"

enum Skin {
    M,
    F
};
class Player : public Entity {
    private:

        /**
         * @brief choix du skin
         */
        Skin skin;

        /**
         * @brief points de vie
         */
        unsigned int hp;

        /**
         * @brief temps où le joueur est invincible après s'être pris un coup
         */
        unsigned int timeInvincible;

        /**
         * @brief vérifie si le déplacement vers le haut est possible
         * 
         * @details renvoie -1 si le déplacement est possible
         * @details retourne un entier positif indiquant le nombre de dégats si le déplacement est impossible
         * 
         * @param position 
         * @param R 
         * @return int 
         */
        int isMovePossibleUp(const Vector2D & position, Room * R) const;

        /**
         * @brief vérifie si le déplacement vers la gauche ou la droite est possible
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
         * @brief vérifie si le déplacement vers le bas est possible
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
         * @brief vérifie si le déplacement vers le bas est possible
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
         * @brief constructeur par défaut
         */
        Player();

        /**
         * @brief constructeur paramétré
         * 
         * @param s
         * @param h
         */
        Player(const Vector2D & p, Skin s, unsigned int health);

        /**
         * @brief baisse les points de vie
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
         * @brief baisse le temps d'invincibilité
         */
        void decreaseTimeInvincible();

        /**
         * @brief déplacement vers le haut (saut)
         * 
         * @param R
         */
        void up(Building * B);

        /**
         * @brief déplacement vers la droite
         * 
         * @param R 
         */
        void right(Building * B);

        /**
         * @brief déplacement vers le bas
         * 
         * @param R 
         */
        void down(Building * B);

        /**
         * @brief déplacement vers la gauche
         * 
         * @param R 
         */
        void left(Building * B);

        /**
         * @brief renvoie si il est sur un block ou non
         * 
         * @param b 
         * @return true 
         * @return false 
         */
        bool standingOnBlock(Building * b);

        /**
         * @brief application de la gravité
         * 
         * @param R 
         */
        void gravity(Building * B);

        /**
         * @brief Get the Hp object
         * 
         * @return unsigned int 
         */
        unsigned int getHp();

        /**
         * @brief Get the Time Invincible object
         * 
         * @return unsigned int 
         */
        unsigned int getTimeInvincible();
        /**
         * @brief test de non-regression
         */
        void regressionTest();
};

#endif
