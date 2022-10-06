"""
A function for reading sdf files
"""

from typing import Optional, Tuple, List


def parse_sdf(
    filename: str, include_hydrogen: Optional[bool] = False
) -> Tuple[List, List]:
    """
    Read an sdf file and return the atom and bond info

    Parameters
    ----------
    filename : str
        The name of the file to analyze
    include_hydrogen : Optional[bool]
        Controls whether information about hydrogens is returned.

    Returns
    -------
    elements : list
        A list of elements
    bonds: list
        A list of tuples where the first two numbers represent the atom indices
        and the third represents the bond order.
    """

    with open(filename) as f:
        data = [x.strip() for x in f.readlines()]

    num_atoms = int(data[3].split()[0])
    num_bonds = int(data[3].split()[1])

    atom_end = 4 + num_atoms
    bond_end = 4 + num_atoms + num_bonds

    atoms = data[4:atom_end]
    bonds = data[atom_end:bond_end]

    elements = [x.split()[3] for x in atoms]

    bond_pairs = [
        (int(x.split()[0]), int(x.split()[1]), int(x.split()[2])) for x in bonds
    ]

    if include_hydrogen is not True:
        bond_pairs = [
            x
            for x in bond_pairs
            if elements[x[0] - 1] != "H" and elements[x[1] - 1] != "H"
        ]
        elements = [x for x in elements if x != "H"]

    # Fix so that bond indices use python indexing
    bond_pairs = [(x[0] - 1, x[1] - 1, x[2]) for x in bond_pairs]

    return elements, bond_pairs
