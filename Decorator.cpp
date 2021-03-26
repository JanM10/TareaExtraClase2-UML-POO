#include <iostream>
#include <string>

using namespace std;

class Ventana{
public:
    virtual ~Ventana() {}
    virtual void dibujar() = 0;
    virtual string obtenerDescripcion() = 0;
};

class VentanaSencilla : public Ventana{
public:
    void dibujar() {
        //Esto dibuja la ventana
    }
    string obtenerDescripcion() {
        return "Ventana Sencilla\n";
    }
};

class DecoradorDeVentana : public Ventana{
protected:
    Ventana *m_ventanaDecorada;

public:
    DecoradorDeVentana (Ventana *ventanaDecorada):
            m_ventanaDecorada(ventanaDecorada) {}
};

class ScrollBarVerticalDecorador : public DecoradorDeVentana{
public:
    ScrollBarVerticalDecorador (Ventana *ventanaDecorada):
            DecoradorDeVentana(ventanaDecorada) {}

    void dibujar() {
        dibujarScrollBarVertical();
        m_ventanaDecorada->dibujar();
    }

    string obtenerDescripcion() {
        return m_ventanaDecorada->obtenerDescripcion() + "con un scrollbar vertical\n";
    }

private:
    void dibujarScrollBarVertical() {
        //Dibuja el scrollbar vertical
    }
};

int main(){
    Ventana *simple = new VentanaSencilla();
    cout << simple -> obtenerDescripcion() << endl;

    Ventana *vert = new ScrollBarVerticalDecorador ( new VentanaSencilla());
    cout << vert -> obtenerDescripcion() << endl;

    return 0;
}








