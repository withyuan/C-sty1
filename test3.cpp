#include <iostream>



class  Printable{
public:
    virtual std::string getclassname()=0;

};
class Entity:public Printable{

public:
    int x,y;
    Entity(){
        std::cout <<this<< "创建了" << std::endl;
        x=0;
        y=0;
    }
    Entity(int x,int y){
        std::cout <<this<< "创建了" << std::endl;
        this->x=x;
        this->y=y;
    }
    ~Entity(){
        std::cout <<this<< "销毁了" << std::endl;
    }
    void print(){
        std::cout << x << "," << y << std::endl;
    };
    void move(int a,int b){
        x+=a;
        y+=b;
        std::cout << "移动了 " << x << "," << y << std::endl;
    }
    virtual  std::string getname(){
        return "Entity";
    };
    std::string getclassname() override  {
        return "Entity";
    }

};


class Player : public Entity{
private:
    std::string m_name;
public:
    Player(const std::string& name):m_name(name){
    }
    std::string  getname() override{
        return m_name;
    }
    std::string getclassname() override  {
        return "Player";
    }

};


void print(Printable* e){
    std::cout << e->getclassname() << std::endl;
}

int main() {
    Entity* e=new Entity();
    print(e);
    Player* p=new Player("张三");
    print(p);
    Entity* e1=p;
    print(e1);



    // Entity e(1,2);
    // std::cout <<e.x << std::endl;
    // e.print();
    // // Entity* e1=new Entity(3,4);
    // // e1->print();
    // // delete e1;
    // std::cout <<e.y << std::endl;
    // // Player p;
    // p.move(2,3);
    // Player* p=new Player();
    // p->move(2,3);
    // std::cout <<sizeof(Player) << std::endl;

    std::cin.get();
    return 0;
}