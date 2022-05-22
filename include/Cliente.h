#ifndef CLIENTE_H
#define CLIENTE_H


class Cliente
{
    public:
        Cliente();
        virtual ~Cliente();
        void setEstado(int Valor);
        int getEstado();
        void setPosicion(int Valor);
        int getPosicion();

    protected:

    private:
        int Estado;
        int Posicion;
};

#endif // CLIENTE_H
