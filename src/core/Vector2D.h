#ifndef _VECTOR2D
#define _VECTOR2D

class Vector2D {
    private:

        /**
         * @brief coordonnee x
         */
        unsigned int x;

        /**
         * @brief coordonnee y
         */
        unsigned int y;

    public:

        /**
         * @brief Constructeur par defaut
         * 
         */
        Vector2D();

        /**
         * @brief Constructeur parametre
         * 
         * @param Vx 
         * @param Vy 
         */
        Vector2D(unsigned int Vx , unsigned int Vy);

        /**
         * @brief retourne la coordonnee x
         * 
         * @return unsigned int 
         */
        unsigned int getX() const;

        /**
         * @brief retourne la coordonnee y
         * 
         * @return unsigned int 
         */
        unsigned int getY() const;

        /**
         * @brief change la coordonnee x
         */
        void setX(unsigned int Vx);

        /**
         * @brief change la coordonnee y
         */
        void setY(unsigned int Vy);

        /**
         * @brief test de non-regression
         */
        void regressionTest();
};

#endif