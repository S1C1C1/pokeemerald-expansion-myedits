#include "global.h"
#include "pokemon.h"
#include "obtainable_species.h"
#include "constants/pokedex.h"

// The only Pokémon that can be caught or received in this hack.
// Rule: start from the weakest Pokémon by base stat total (one entry per National
// Dex number, base forms, Feebas and Magikarp left out) and drop every evolution
// line that can reach a final form with a BST of 350 or more without items or
// trading. Only 47 Pokémon in the whole game pass, so all of them are listed.
// Most of these can't evolve, because their evolutions need stones (replaced
// with Full Restores in this hack), held items or trading.
// Any form of a listed Pokémon is also allowed.
static const u16 sObtainableNationalDexNums[] =
{
    NATIONAL_DEX_PIKACHU,             // BST 320
    NATIONAL_DEX_CLEFAIRY,            // BST 323
    NATIONAL_DEX_VULPIX,              // BST 299
    NATIONAL_DEX_JIGGLYPUFF,          // BST 270
    NATIONAL_DEX_SHELLDER,            // BST 305
    NATIONAL_DEX_EXEGGCUTE,           // BST 325
    NATIONAL_DEX_STARYU,              // BST 340
    NATIONAL_DEX_DITTO,               // BST 288
    NATIONAL_DEX_PICHU,               // BST 205
    NATIONAL_DEX_CLEFFA,              // BST 218
    NATIONAL_DEX_IGGLYBUFF,           // BST 210
    NATIONAL_DEX_SUNKERN,             // BST 180
    NATIONAL_DEX_UNOWN,               // BST 336
    NATIONAL_DEX_DELIBIRD,            // BST 330
    NATIONAL_DEX_SMEARGLE,            // BST 250
    NATIONAL_DEX_LOTAD,               // BST 220
    NATIONAL_DEX_LOMBRE,              // BST 340
    NATIONAL_DEX_SEEDOT,              // BST 220
    NATIONAL_DEX_NUZLEAF,             // BST 340
    NATIONAL_DEX_SKITTY,              // BST 260
    NATIONAL_DEX_CLAMPERL,            // BST 345
    NATIONAL_DEX_LUVDISC,             // BST 330
    NATIONAL_DEX_HAPPINY,             // BST 220
    NATIONAL_DEX_PANSAGE,             // BST 316
    NATIONAL_DEX_PANSEAR,             // BST 316
    NATIONAL_DEX_PANPOUR,             // BST 316
    NATIONAL_DEX_MUNNA,               // BST 292
    NATIONAL_DEX_COTTONEE,            // BST 280
    NATIONAL_DEX_PETILIL,             // BST 280
    NATIONAL_DEX_MINCCINO,            // BST 300
    NATIONAL_DEX_KARRABLAST,          // BST 315
    NATIONAL_DEX_SHELMET,             // BST 305
    NATIONAL_DEX_SPRITZEE,            // BST 341
    NATIONAL_DEX_SWIRLIX,             // BST 341
    NATIONAL_DEX_HELIOPTILE,          // BST 289
    NATIONAL_DEX_PHANTUMP,            // BST 309
    NATIONAL_DEX_PUMPKABOO,           // BST 335
    NATIONAL_DEX_WISHIWASHI,          // BST 175
    NATIONAL_DEX_MELTAN,              // BST 300
    NATIONAL_DEX_APPLIN,              // BST 260
    NATIONAL_DEX_SINISTEA,            // BST 308
    NATIONAL_DEX_MILCERY,             // BST 270
    NATIONAL_DEX_CHARCADET,           // BST 255
    NATIONAL_DEX_TADBULB,             // BST 272
    NATIONAL_DEX_CAPSAKID,            // BST 304
    NATIONAL_DEX_CETODDLE,            // BST 334
    NATIONAL_DEX_POLTCHAGEIST,        // BST 308
};

bool32 IsSpeciesObtainable(enum Species species)
{
    u32 i;
    enum NationalDexOrder natDexNum;

    if (!P_RESTRICT_OBTAINABLE_SPECIES || TESTING)
        return TRUE;

    natDexNum = SpeciesToNationalPokedexNum(species);
    if (natDexNum == NATIONAL_DEX_NONE)
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sObtainableNationalDexNums); i++)
    {
        if (sObtainableNationalDexNums[i] == natDexNum)
            return TRUE;
    }
    return FALSE;
}
