#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie object inited" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}
