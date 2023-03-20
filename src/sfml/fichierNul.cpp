/**
         * @brief Convertit les coordonnees en pixels en coordonnees en cellules
         * 
         * @param Pixel 
         * @return Vector2D*
         */
        Vector2D* pixelToCell(const Vector2D & Pixel) const; // a mettre dans l'affichage

Vector2D* Room::pixelToCell(const Vector2D & Pixel) const {
    Vector2D* V = new Vector2D(Pixel.getX()*DIM_ROOM_X/PIXEL_ROOM_X, Pixel.getY()*DIM_ROOM_Y/PIXEL_ROOM_Y);
    return V;
}