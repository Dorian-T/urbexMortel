#ifndef _VECTOR2D
#define _VECTOR2D

/**
 * @brief Classe représentant un vecteur à deux dimension, x et y
 */
class Vector2D {
    private:

        /**
         * @brief Coordonnée x
         */
        unsigned int x;

        /**
         * @brief Coordonnée y
         */
        unsigned int y;

    public:

        /**
         * @brief Constructeur par défaut
         * 
         */
        Vector2D();

        /**
         * @brief Constructeur paramétré
         * 
         * @param Vx 
         * @param Vy 
         */
        Vector2D(unsigned int Vx , unsigned int Vy);

        /**
         * @brief Retourne la coordonnée x
         * 
         * @return unsigned int 
         */
        unsigned int getX() const;

        /**
         * @brief Retourne la coordonnée y
         * 
         * @return unsigned int 
         */
        unsigned int getY() const;

        /**
         * @brief Change la coordonnée x
         */
        void setX(unsigned int Vx);

        /**
         * @brief Change la coordonnée y
         */
        void setY(unsigned int Vy);

        Vector2D operator+(const Vector2D & v) const;

        /**
         * @brief Test de non-regression
         */
        void regressionTest();
};

#endif