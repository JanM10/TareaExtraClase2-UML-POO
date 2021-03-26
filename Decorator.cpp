#include <iostream>
#include <string>

using namespace std;

class Ventana
{
public:
    virtual ~Ventana() {}
    virtual void dibujar() = 0;
    virtual string obtenerDescripcion() = 0;
};

class VentanaSencilla : public Ventana
{
public:
    void dibujar() {
        //Esto dibuja la ventana
    }
    string obtenerDescripcion() {
        return "Ventana Sencilla\n";
    }
};

int main(){
    return 0;
}


