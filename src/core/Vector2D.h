#ifndef _VECTOR2D
#define _VECTOR2D

class Vector2D
{
private:
    unsigned int x;
    unsigned int y;/* data */
public:
    /**
     * @brief Constructeur par défaut
     * 
     */
    Vector2D();

    /**
     * @brief Constructeur avec coordonnée intégré 
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
    unsigned int getX();

    /**
     * @brief retourne la coordonnée y
     * 
     * @return unsigned int 
     */
    unsigned int getY();

    /**
     * @brief change la coordonnée x
     * 
     */
    void setX(unsigned int Vx);

    /**
     * @brief change la coordonnée y
     * 
     */
    void setY(unsigned int Vy);
    
    /**
     * @brief affiche un vector
     * 
     */
    void displayVector();

    /**
     * @brief verifie que tout le module Vector2D fonctionne
     * 
     */
    void regressionTest();
};

#endif
