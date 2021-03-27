#include <iostream>

using namespace std;

class Handler {
protected:
    Handler *siguiente;

public:
    Handler() { siguiente = NULL; }
    void fijarSiguenteHandler(Handler *siguenteEnLinea) {
        siguiente = siguenteEnLinea;
    }
    virtual void solicitar(int value) = 0;

};

class elegirHandler : public Handler {
private:
    int ID;
    int limite;


public:
    elegirHandler(int el_ID, int el_Limite) {
        ID = el_ID;
        limite = el_Limite;
    }

    void solicitar(int valor) {
        if (valor < limite) {
            cout << "El Handler " << ID << " gestiono la solicitud con un limite de " << limite << endl;
        }else if (siguiente != NULL) {
            siguiente->solicitar(valor);
        }else {
            cout << "Hubo un error, el Handler " << ID << " no pudo gestionar la solicitud." << endl;
        }
    }
};

int main (){
    Handler *h1 = new elegirHandler(1, 3242);
    Handler *h2 = new elegirHandler(2, 23);
    Handler *h3 = new elegirHandler(3, 89);

    h1->fijarSiguenteHandler(h2);
    h2->fijarSiguenteHandler(h3);

    h1->solicitar(18);
    h1->solicitar(0);
    h3->solicitar(634);
    h2->solicitar(14);

    delete h1;
    delete h2;
    delete h3;

    return 0;

}

