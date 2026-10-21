#include "global.h"
#include "pokemon.h"
#include "obtainable_species.h"
#include "constants/pokedex.h"

// The only Pokémon that can be caught or received in this hack:
// the 150 Pokémon with the lowest base stat totals (one entry per National Dex
// number, using each species' base form), with Feebas and Magikarp left out.
// Ties at the cutoff (BST 300) are broken by National Dex order.
// Any form of a listed Pokémon (e.g. Alolan Rattata) is also allowed.
static const u16 sObtainableNationalDexNums[] =
{
    NATIONAL_DEX_CATERPIE,            // BST 195
    NATIONAL_DEX_METAPOD,             // BST 205
    NATIONAL_DEX_WEEDLE,              // BST 195
    NATIONAL_DEX_KAKUNA,              // BST 205
    NATIONAL_DEX_PIDGEY,              // BST 251
    NATIONAL_DEX_RATTATA,             // BST 253
    NATIONAL_DEX_SPEAROW,             // BST 262
    NATIONAL_DEX_EKANS,               // BST 288
    NATIONAL_DEX_SANDSHREW,           // BST 300
    NATIONAL_DEX_NIDORAN_F,           // BST 275
    NATIONAL_DEX_NIDORAN_M,           // BST 273
    NATIONAL_DEX_VULPIX,              // BST 299
    NATIONAL_DEX_JIGGLYPUFF,          // BST 270
    NATIONAL_DEX_ZUBAT,               // BST 245
    NATIONAL_DEX_PARAS,               // BST 285
    NATIONAL_DEX_DIGLETT,             // BST 265
    NATIONAL_DEX_MEOWTH,              // BST 290
    NATIONAL_DEX_POLIWAG,             // BST 300
    NATIONAL_DEX_BELLSPROUT,          // BST 300
    NATIONAL_DEX_GEODUDE,             // BST 300
    NATIONAL_DEX_HORSEA,              // BST 295
    NATIONAL_DEX_DITTO,               // BST 288
    NATIONAL_DEX_DRATINI,             // BST 300
    NATIONAL_DEX_SENTRET,             // BST 215
    NATIONAL_DEX_HOOTHOOT,            // BST 262
    NATIONAL_DEX_LEDYBA,              // BST 265
    NATIONAL_DEX_SPINARAK,            // BST 250
    NATIONAL_DEX_PICHU,               // BST 205
    NATIONAL_DEX_CLEFFA,              // BST 218
    NATIONAL_DEX_IGGLYBUFF,           // BST 210
    NATIONAL_DEX_TOGEPI,              // BST 245
    NATIONAL_DEX_MAREEP,              // BST 280
    NATIONAL_DEX_MARILL,              // BST 250
    NATIONAL_DEX_HOPPIP,              // BST 250
    NATIONAL_DEX_SUNKERN,             // BST 180
    NATIONAL_DEX_WOOPER,              // BST 210
    NATIONAL_DEX_PINECO,              // BST 290
    NATIONAL_DEX_SNUBBULL,            // BST 300
    NATIONAL_DEX_SLUGMA,              // BST 250
    NATIONAL_DEX_SWINUB,              // BST 250
    NATIONAL_DEX_SMEARGLE,            // BST 250
    NATIONAL_DEX_TYROGUE,             // BST 210
    NATIONAL_DEX_POOCHYENA,           // BST 220
    NATIONAL_DEX_ZIGZAGOON,           // BST 240
    NATIONAL_DEX_WURMPLE,             // BST 195
    NATIONAL_DEX_SILCOON,             // BST 205
    NATIONAL_DEX_CASCOON,             // BST 205
    NATIONAL_DEX_LOTAD,               // BST 220
    NATIONAL_DEX_SEEDOT,              // BST 220
    NATIONAL_DEX_TAILLOW,             // BST 270
    NATIONAL_DEX_WINGULL,             // BST 270
    NATIONAL_DEX_RALTS,               // BST 198
    NATIONAL_DEX_KIRLIA,              // BST 278
    NATIONAL_DEX_SURSKIT,             // BST 269
    NATIONAL_DEX_SHROOMISH,           // BST 295
    NATIONAL_DEX_SLAKOTH,             // BST 280
    NATIONAL_DEX_NINCADA,             // BST 266
    NATIONAL_DEX_SHEDINJA,            // BST 236
    NATIONAL_DEX_WHISMUR,             // BST 240
    NATIONAL_DEX_MAKUHITA,            // BST 237
    NATIONAL_DEX_AZURILL,             // BST 190
    NATIONAL_DEX_SKITTY,              // BST 260
    NATIONAL_DEX_MEDITITE,            // BST 280
    NATIONAL_DEX_ELECTRIKE,           // BST 295
    NATIONAL_DEX_TRAPINCH,            // BST 290
    NATIONAL_DEX_BARBOACH,            // BST 288
    NATIONAL_DEX_SHUPPET,             // BST 295
    NATIONAL_DEX_DUSKULL,             // BST 295
    NATIONAL_DEX_WYNAUT,              // BST 260
    NATIONAL_DEX_SPHEAL,              // BST 290
    NATIONAL_DEX_STARLY,              // BST 245
    NATIONAL_DEX_BIDOOF,              // BST 250
    NATIONAL_DEX_KRICKETOT,           // BST 194
    NATIONAL_DEX_SHINX,               // BST 263
    NATIONAL_DEX_BUDEW,               // BST 280
    NATIONAL_DEX_BURMY,               // BST 224
    NATIONAL_DEX_COMBEE,              // BST 244
    NATIONAL_DEX_CHERUBI,             // BST 275
    NATIONAL_DEX_CHINGLING,           // BST 285
    NATIONAL_DEX_BONSLY,              // BST 290
    NATIONAL_DEX_HAPPINY,             // BST 220
    NATIONAL_DEX_RIOLU,               // BST 285
    NATIONAL_DEX_PATRAT,              // BST 255
    NATIONAL_DEX_LILLIPUP,            // BST 275
    NATIONAL_DEX_PURRLOIN,            // BST 281
    NATIONAL_DEX_MUNNA,               // BST 292
    NATIONAL_DEX_PIDOVE,              // BST 264
    NATIONAL_DEX_BLITZLE,             // BST 295
    NATIONAL_DEX_ROGGENROLA,          // BST 280
    NATIONAL_DEX_TYMPOLE,             // BST 294
    NATIONAL_DEX_VENIPEDE,            // BST 260
    NATIONAL_DEX_COTTONEE,            // BST 280
    NATIONAL_DEX_PETILIL,             // BST 280
    NATIONAL_DEX_SANDILE,             // BST 292
    NATIONAL_DEX_GOTHITA,             // BST 290
    NATIONAL_DEX_SOLOSIS,             // BST 290
    NATIONAL_DEX_FOONGUS,             // BST 294
    NATIONAL_DEX_TYNAMO,              // BST 275
    NATIONAL_DEX_LITWICK,             // BST 275
    NATIONAL_DEX_BUNNELBY,            // BST 237
    NATIONAL_DEX_FLETCHLING,          // BST 278
    NATIONAL_DEX_SCATTERBUG,          // BST 200
    NATIONAL_DEX_SPEWPA,              // BST 213
    NATIONAL_DEX_INKAY,               // BST 288
    NATIONAL_DEX_HELIOPTILE,          // BST 289
    NATIONAL_DEX_NOIBAT,              // BST 245
    NATIONAL_DEX_PIKIPEK,             // BST 265
    NATIONAL_DEX_YUNGOOS,             // BST 253
    NATIONAL_DEX_ROCKRUFF,            // BST 280
    NATIONAL_DEX_WISHIWASHI,          // BST 175
    NATIONAL_DEX_DEWPIDER,            // BST 269
    NATIONAL_DEX_FOMANTIS,            // BST 250
    NATIONAL_DEX_MORELULL,            // BST 285
    NATIONAL_DEX_BOUNSWEET,           // BST 210
    NATIONAL_DEX_STEENEE,             // BST 290
    NATIONAL_DEX_WIMPOD,              // BST 230
    NATIONAL_DEX_COSMOG,              // BST 200
    NATIONAL_DEX_SKWOVET,             // BST 275
    NATIONAL_DEX_ROOKIDEE,            // BST 245
    NATIONAL_DEX_BLIPBUG,             // BST 180
    NATIONAL_DEX_NICKIT,              // BST 245
    NATIONAL_DEX_GOSSIFLEUR,          // BST 250
    NATIONAL_DEX_WOOLOO,              // BST 270
    NATIONAL_DEX_CHEWTLE,             // BST 284
    NATIONAL_DEX_YAMPER,              // BST 270
    NATIONAL_DEX_ROLYCOLY,            // BST 240
    NATIONAL_DEX_APPLIN,              // BST 260
    NATIONAL_DEX_ARROKUDA,            // BST 280
    NATIONAL_DEX_TOXEL,               // BST 242
    NATIONAL_DEX_HATENNA,             // BST 265
    NATIONAL_DEX_IMPIDIMP,            // BST 265
    NATIONAL_DEX_MILCERY,             // BST 270
    NATIONAL_DEX_SNOM,                // BST 185
    NATIONAL_DEX_DREEPY,              // BST 270
    NATIONAL_DEX_LECHONK,             // BST 254
    NATIONAL_DEX_TAROUNTULA,          // BST 210
    NATIONAL_DEX_NYMBLE,              // BST 210
    NATIONAL_DEX_PAWMI,               // BST 240
    NATIONAL_DEX_SMOLIV,              // BST 260
    NATIONAL_DEX_NACLI,               // BST 280
    NATIONAL_DEX_CHARCADET,           // BST 255
    NATIONAL_DEX_TADBULB,             // BST 272
    NATIONAL_DEX_WATTREL,             // BST 280
    NATIONAL_DEX_SHROODLE,            // BST 290
    NATIONAL_DEX_BRAMBLIN,            // BST 275
    NATIONAL_DEX_RELLOR,              // BST 270
    NATIONAL_DEX_FLITTLE,             // BST 255
    NATIONAL_DEX_TINKATINK,           // BST 297
    NATIONAL_DEX_WIGLETT,             // BST 245
    NATIONAL_DEX_GREAVARD,            // BST 290
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
