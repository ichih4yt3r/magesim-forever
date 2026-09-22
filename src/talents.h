#pragma once

struct Talents
{
    // ARCANE TALENTS
     //wrath stuff - keep for reference
    int magic_attunement = 0;
    int spell_impact = 0; //x
    int student_of_the_mind = 0; //x
    int focus_magic = 0; //x
    int arcane_shielding = 0; 
    int torment_of_the_weak = 0; //x
    int arcane_potency = 0; //x
    int arcane_empowerment = 0; //x 
    int incanters_absorption = 0; //x 
    int arcane_floes = 0; //x
    int mind_mastery = 0; //x
    int netherwind_presence = 0; //x
    int spell_power = 0; //x
    int arcane_barrage = 0; //x

    // Remained unchanged and IN 
    int presence_of_mind = 0; // 3min cd next spell under 10s instacast
    int clearcast = 0;
    int wand_specialization = 0;

    /*Changed*/
    int arcane_focus = 0; // 1% hit with arcane spells
    int arcane_subtley = 0; // reduces target resistance of all spells by 8 x2, and threat of arcane spells by 15% x2
    int magic_absorption = 0; // increase all res by 5, all spells fully resisted restores 1% total mana. no more then 1 per sec
    int arcane_impact = 0; // crit of arcane spells by 2% x 3
    int arcane_meditation = 0; // 17 33 50 mana regen while casting
    int missile_barrage = 0; //AB 40% chance; fb frb ffb 20% chance to reduce channel of AM by 50% reduce mana by 100%, missile fire ever 0.5s
    int arcane_mind = 0; // 2% intellect x5, increase arcane Crit Damage by 20% x5
    int arcane_instability = 0; // 1% damage of all spells, 1% crit of all attacks
    int arcane_power = 0; // 15s deal 30% more damage while costing 30% MORE mana

    /* NEW */
    int arcane_blast = 0; // NEW 2.5s cast, some dmg, 10% increased damage, 175% mana, up to 4, last 8s or any other damage spell cast.
    int arcane_geometry = 0; //Arcane Spell Range by 3 x2
    int improved_channeling = 0; // 20% x5 chance to avoid interuption by damage while channeling AM and 14% x5 casting AB 



    // FIRE TALENTS

    //wrath stuff - keep for reference
    int world_in_flames = 0;
    int playing_with_fire = 0;
    int pyromaniac = 0;
    int molten_fury = 0;
    int empowered_fire = 0;
    int firestarter = 0;
    int dragons_breath = 0;
    int burnout = 0;
    int living_bomb = 0;

    // remained unchanged and IN
    int imp_fire_blast = 0; // changed to wake of fire
    int flame_throwing = 0; // 3meters range x2
    int master_of_elements = 0;
    int critical_mass = 0;
    int blast_weave = 0;
    int fire_power = 0;

    // Changed
    int incineration = 0;
    int imp_fireball = 0;
    int ignite = 0;
    int burning_soul = 0; // fire spells chance to not lose casting time 23% x3, reduced threat. 
    int imp_flamestrike = 0; // crit 5% for flamestrike x3
    int pyroblast = 0; // 6s high damage spell with dot. 
    int imp_scorch = 0; // 33% x3 chance to vuln to fire damage. vuln = 3% more damage stack to 5. 
    int combustion = 0; // increased fire crit strike chance by 10%, until 4 crits (not dots). 

    // NEW
    int wake_of_fire = 0; //reduce FBlast by 1sec x2.
    int hot_streak = 0; // non-dot Crits grant Buff, reduces Pyroblast cast time by 25% x3 (75% faster or 1.5sec)
    


    // FROST TALENTS
    //wrath stuff - keep for reference
    int ice_floes = 0;
    int icy_veins = 0;
    int cold_as_ice = 0;
    int arctic_winds = 0;
    int empowered_frostbolt = 0;
    int brain_freeze = 0;
    int water_elemental = 0;
    int enduring_winter = 0;
    int chilled_to_the_bone = 0;
    int deep_freeze = 0;

    // remained unchanged and IN
    int imp_frostbolt = 0; //
    int ice_shards = 0; //20% crit x5 damage bonus for frost spells (100% crit chance)
    int piercing_ice = 0; // 2% damage of frost spells - up to 6% total.

    // Changed
    int precision = 0; // 1% flat x5 for fire and frost spells
    int permafrost = 0; // chill duration by 11% x3 target speed by 3% x3
    int frost_channeling = 0; // mana cost reduction of frost spells by 5% x3 and threat by 10% x3
    int shatter = 0;
    int imp_cone_of_cold = 0;
    int cold_snap = 0;
    int winters_chill = 0;


    // NEW
    int ice_lance = 0; // damage isntant 30yd 45 mana, 300% on frozen target.
    int fingers_of_frost = 0;
     

};

struct Glyphs // inactive atm
{
    // Major
    bool arcane_barrage = false;
    bool arcane_blast = false;
    bool arcane_explosion = false;
    bool arcane_missiles = false;
    bool arcane_power = false;
    bool eternal_water = false;
    bool fireball = false;
    bool frostbolt = false;
    bool frostfire = false;
    bool ice_lance = false;
    bool living_bomb = false;
    bool mage_armor = false;
    bool mana_gem = false;
    bool mirror_image = false;
    bool molten_armor = false;
    bool scorch = false;
    bool water_elemental = false;

    // Minor
    bool blast_wave = false;
};