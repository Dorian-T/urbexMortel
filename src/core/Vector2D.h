#ifndef _VECTOR2D
#define _VECTOR2D

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
         * @brief constructeur par défaut
         * 
         */
        Vector2D();

        /**
         * @brief constructeur paramétré
         * 
         * @param Vx 
         * @param Vy 
         */
        Vector2D(unsigned int Vx , unsigned int Vy);

        /**
         * @brief retourne la coordonnée x
         * 
         * @return unsigned int 
         */
        unsigned int getX() const;

        /**
         * @brief retourne la coordonnée y
         * 
         * @return unsigned int 
         */
        unsigned int getY() const;

        /**
         * @brief change la coordonnée x
         */
        void setX(unsigned int Vx);

        /**
         * @brief change la coordonnée y
         */
        void setY(unsigned int Vy);

        /**
         * @brief test de non-regression
         */
        void regressionTest();
};

#endif