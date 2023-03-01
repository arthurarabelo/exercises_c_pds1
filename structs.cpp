#include <stdio.h> 
#include <math.h>
#include <stdbool.h>

struct Ponto {
 float x;
 float y;

 float distancia(Ponto& p);

 void atribuir(float a, float b);
};

void Ponto::atribuir(float a, float b){
    this->x = a;
    this->y = b;  
}

float Ponto::distancia(Ponto& p){
    return (sqrt(pow((p.x - this->x),2)+pow((p.y - this->y),2)));
}

struct Triangulo{
    Ponto p1, p2, p3;

    float perimetro();
    float area();
    bool equilatero();
    bool semelhante(Triangulo& t);
};

float Triangulo::perimetro(){
    return (this->p1.distancia(this->p2)+this->p1.distancia(this->p3)+this->p2.distancia(this->p3));
}

float Triangulo::area(){
    float semiP = this->perimetro() / 2;
    return (sqrt(semiP*(semiP - this->p1.distancia(this->p2))*
    (semiP - this->p1.distancia(this->p3))*
    (semiP - this->p2.distancia(this->p3))));
}

bool Triangulo::equilatero(){
    return(this->p1.distancia(this->p2)==this->p1.distancia(this->p3) && 
    this->p1.distancia(this->p3)==this->p2.distancia(this->p3));
}

bool Triangulo::semelhante(Triangulo& t){
    float k = t.p1.distancia(t.p2) / this->p1.distancia(this->p2);
    return((t.p1.distancia(t.p3) / this->p1.distancia(this->p3))==k && 
    (t.p2.distancia(t.p3) / this->p2.distancia(this->p3))==k);
}

struct Retangulo{
    Ponto p1, p2, p3, p4;

    float perimetro();
    float area();
    bool quadrado();
};

float Retangulo::perimetro(){
    return ((this->p1.distancia(this->p2)*2) + (this->p1.distancia(this->p4))*2);
}

float Retangulo::area(){    
    return ((this->p1.distancia(this->p2))*(this->p1.distancia(this->p4)));
}

bool Retangulo::quadrado(){
    return((this->p1.distancia(this->p2))==(this->p1.distancia(this->p4)));
}

struct Circunferencia{
    Ponto centro;
    float raio;

    float perimetro();
    float area();
    bool contem(Ponto& p);
    bool contem(Triangulo& t);
    bool contem(Retangulo& r);
    bool pertence(Ponto& p);
    bool circunscrita(Triangulo& t);
    bool circunscrita(Retangulo& r);
};

float Circunferencia::perimetro(){
    return (3.14*2*this->raio);
}

float Circunferencia::area(){
    return (3.14*(pow(this->raio, 2)));
}

bool Circunferencia::contem(Ponto& p){
    return((p.distancia(this->centro))<=this->raio);
}

bool Circunferencia::contem(Triangulo& t){
    if (t.p1.distancia(this->centro)<= this->raio && 
        t.p2.distancia(this->centro)<= this->raio &&
        t.p3.distancia(this->centro)<= this->raio) 
        return true;    
    else return false;
}
    
bool Circunferencia::contem(Retangulo& r){
    if (r.p1.distancia(this->centro)<= this->raio && 
        r.p2.distancia(this->centro)<= this->raio &&
        r.p3.distancia(this->centro)<= this->raio &&
        r.p4.distancia(this->centro)<= this->raio) 
        return true;    
    else return false;
}   

bool Circunferencia::pertence(Ponto& p){
    return ((p.distancia(this->centro))==this->raio);
}

bool Circunferencia::circunscrita(Triangulo& t){
    if (t.p1.distancia(this->centro)== this->raio && 
        t.p2.distancia(this->centro)== this->raio &&
        t.p3.distancia(this->centro)== this->raio)
        return true;
    else return false;
}

bool Circunferencia::circunscrita(Retangulo& r){
    if (r.p1.distancia(this->centro)== this->raio && 
        r.p2.distancia(this->centro)== this->raio &&
        r.p3.distancia(this->centro)== this->raio &&
        r.p4.distancia(this->centro)== this->raio) 
        return true;    
    else return false;
}


int main(){
    Ponto p1, p2;
    p1.atribuir(0, 0);
    p2.atribuir(3, 0);
    printf("a distancia entre p1 e p2 eh: %f\n", p1.distancia(p2));
    Triangulo t;
    t.p1.atribuir(0,0);
    t.p2.atribuir(2,2);
    t.p3.atribuir(2,0);
    printf("o perimetro do triangulo eh: %f\n", t.perimetro());
    printf("a area do triangulo eh: %f\n", t.area());
    printf("o triangulo eh equilatero? %d\n", t.equilatero());
    Triangulo t2;
    t2.p1.atribuir(0,0);
    t2.p2.atribuir(4,4);
    t2.p3.atribuir(4,0);
    printf("t1 e t2 sao semelhantes? %d\n", t.semelhante(t2));
    Retangulo r;
    r.p1.atribuir(0,0);
    r.p2.atribuir(0,1);
    r.p3.atribuir(4,1);
    r.p4.atribuir(4,0);
    printf("o perimetro do retangulo eh: %f\n", r.perimetro());
    printf("a area do retangulo eh: %f\n", r.area());
    printf("o retangulo eh quadrado? %d\n", r.quadrado());
    Circunferencia c;
    c.raio = 2;
    c.centro.atribuir(0,0);
    printf("o perimetro da circunferencia eh: %f\n", c.perimetro());
    printf("a area da circunferencia eh: %f\n", c.area());
    printf("a circunferencia contem o ponto? %d\n", c.contem(p2));
    printf("a circunferencia contem o triangulo? %d\n", c.contem(t));
    printf("a circunferencia contem o retangulo? %d\n", c.contem(r));
    printf("o ponto pertence a linha da circunferencia? %d\n", c.pertence(p1));
    printf("a circunferencia eh circunscrita no triangulo? %d\n", c.circunscrita(t));
    printf("a circunferencia eh circunscrita no retangulo? %d\n", c.circunscrita(r));
}
