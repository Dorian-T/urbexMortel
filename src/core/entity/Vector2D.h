#ifndef _VECTOR2D
#define _VECTOR2D

/**
 * @brief Classe représentant un vecteur à deux dimension, x et y
 */
class Vector2D {
    private:

        /**
         * @brief coordonnée x
         */
        unsigned int x;

        /**
         * @brief coordonnée y
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
         * @brief Accesseur de la coordonnée x
         * 
         * @return unsigned int 
         */
        unsigned int getX() const;

        /**
         * @brief Accesseur de la coordonnée y
         * 
         * @return unsigned int 
         */
        unsigned int getY() const;

        /**
         * @brief Mutateur de la coordonnée x
         */
        void setX(unsigned int Vx);

        /**
         * @brief Mutateur de la coordonnée y
         */
        void setY(unsigned int Vy);

        /**
         * @brief Surcharge de l'opérateur +
         * 
         * @param V 
         * @return Vector2D 
         */
        Vector2D operator+(const Vector2D & V) const;

        /**
         * @brief Renvoie la distance entre deux points
         * 
         * @param V 
         * @return float 
         */
        float distance(const Vector2D & V) const;

        /**
         * @brief Tests de non-regression
         */
        void regressionTest();
};

#endif