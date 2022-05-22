#ifndef BARBERO_H
#define BARBERO_H


class Barbero
{
    public:
        Barbero();
        virtual ~Barbero();
        void setEstado(int Valor);
        int getEstado();
        void setPosicion(int Valor);
        int getPosicion();

    protected:

    private:
        int Estado;//Semaforo Binario del Barbero
        int Posicion;//Guarda la ultima posicion del Barbero
};

#endif // BARBERO_H
