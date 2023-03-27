#include <iostream>

class CPolygon {
   protected:
    int height, width;

   public:
    void set_values(int h, int w) {
        height = h;
        width = w;
    }

    virtual int area() { return width * height; }
};

class CRectangle : public CPolygon {};

class CTriangle : public CPolygon {
   public:
    virtual int area() { return (width * height) / 2; }
};

int main() {
    CRectangle rect;
    CTriangle trgl;
    CPolygon poly;

    CPolygon *pRect = &rect;
    CPolygon *pTrgl = &trgl;
    CPolygon *pPoly = &poly;

    pRect->set_values(10, 5);
    pTrgl->set_values(15, 12);
    pPoly->set_values(10, 10);

    std::cout << "Area: " << pRect->area();
    std::cout << "Area: " << pTrgl->area();
    std::cout << "Area: " << pPoly->area();
}