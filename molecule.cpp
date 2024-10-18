#include <iostream>
#include <cassert>

#include <vector>
#include <array>

struct Atom
{
    std::string symbol; //!< Atomic symbol (H, Li, etc)
    double x;           //!< X-coordinate
    double y;           //!< Y-coordinate
    double z;           //!< Z-coordinate
};


class Molecule
{
    private:
        std::vector<Atom> atoms_;

    public:
        Molecule() {}

        Molecule(const std::vector<Atom> & atoms) : atoms_(atoms) {}

        void add_atom(const Atom & atom) { atoms_.push_back(atom); }

        size_t size() const { return atoms_.size(); }
};


int main(void)
{
    /* Some testing code below */
    Molecule h2;

    // 2 Hydrogen atoms
    h2.add_atom(Atom{"H", 0.0, 0.0, 0.0});
    h2.add_atom(Atom{"H", 0.0, 0.0, 1.0});

    std::cout << h2 << std::endl;

    // Changing via reference from get_atom
    Atom & a2 = h2[0];
    a2.x = 4.0;

    Atom & a = h2[0];
    assert(a.x == 4.0);
    assert(a.y == 0.0);
    assert(a.z == 0.0);

    // Testing copy constructor and const correctness
    const Molecule h2c(h2);
    const Atom & ac = h2c[0];
    assert(ac.x == 4.0);
    assert(ac.y == 0.0);
    assert(ac.z == 0.0);
    assert(h2c.size() == 2);

    // Constructing with vector & moment of inertia
    std::vector<Atom> atoms;
    atoms.push_back(Atom{"O", 1.0000,  1.0000,  0.2404});
    atoms.push_back(Atom{"H", 1.0000,  2.4326, -0.9611});
    atoms.push_back(Atom{"H", 1.0000, -2.4326, -0.9611});

    Molecule h2o(atoms);
    std::cout << "Molecular weight: " << h2o.molecular_weight() << std::endl;
    std::cout << "Nuclear repulsion energy: " << h2o.nuclear_repulsion() << std::endl;


    ///* Feel free to add more! */

    return 0;
}
