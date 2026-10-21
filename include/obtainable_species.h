#ifndef GUARD_OBTAINABLE_SPECIES_H
#define GUARD_OBTAINABLE_SPECIES_H

// Returns TRUE if the player is allowed to catch or receive this species.
// See src/obtainable_species.c for the list.
bool32 IsSpeciesObtainable(enum Species species);

#endif // GUARD_OBTAINABLE_SPECIES_H
