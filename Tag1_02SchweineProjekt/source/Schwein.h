#pragma once
#include <ostream>
#include <string>
#include <stdexcept>
#include <stdexcept>
class Schwein
{
	std::string name;
	int gewicht;

    void setGewicht(int gewicht_) {
        Schwein::gewicht = gewicht_;
    }
public:
    explicit Schwein(const std::string &name = "Nobody")  {
        setName(name);
    }

    void setName(const std::string &name_) {
        if(name_ == "Elsa") throw std::invalid_argument{"Name ist nicht erlaubt"};
        Schwein::name = name_;
    }
    void fuettern() {
        setGewicht(getGewicht() + 1);
    }


    // Generated Code---------------------------

    const std::string &getName() const {
        return name;
    }



    int getGewicht() const {
        return gewicht;
    }

     bool operator==(const Schwein &rhs) const {
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }
};


