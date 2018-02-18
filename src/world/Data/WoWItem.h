/*
Copyright (c) 2014-2018 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

/*
 * THIS IS A WOW DATA STRUCT FILE
 *
 * DO NOT ADD ADDITIONAL MEMBERS TO IT
 *
 * DO NOT EDIT IT UNLESS YOU KNOW EXACTLY WHAT YOU ARE DOING
 */

#pragma once
#include "WoWObject.h"
#pragma pack(push, 1)

#if VERSION_STRING == Classic

#define WOWITEM_SPELL_CHARGES_COUNT 5
#define WOWITEM_ENCHANTMENT_COUNT 21

struct WoWItem : WoWObject
{
    union
    {
        struct
        {
            uint32_t low;
            uint32_t high;
        } owner_guid_parts;

        uint64_t owner_guid;
    };
    uint64_t container_guid;
    uint64_t creator_guid;
    uint64_t gift_creator_guid;
    uint32_t stack_count;
    uint32_t duration;
    int32_t spell_charges[WOWITEM_SPELL_CHARGES_COUNT];
    uint32_t flags;
    uint32_t enchantment[WOWITEM_ENCHANTMENT_COUNT];
    uint32_t property_seed;
    uint32_t random_properties_id;
    uint32_t item_text_id;
    uint32_t durability;
    uint32_t max_durability;
};
#endif

#if VERSION_STRING == TBC

#define WOWITEM_SPELL_CHARGES_COUNT 5
#define WOWITEM_ENCHANTMENT_COUNT 33

struct WoWItem : WoWObject
{
    union
    {
        struct
        {
            uint32_t low;
            uint32_t high;
        } owner_guid_parts;

        uint64_t owner_guid;
    };
    uint64_t container_guid;
    uint64_t creator_guid;
    uint64_t gift_creator_guid;
    uint32_t stack_count;
    uint32_t duration;
    int32_t spell_charges[WOWITEM_SPELL_CHARGES_COUNT];
    uint32_t flags;
    uint32_t enchantment[WOWITEM_ENCHANTMENT_COUNT];
    uint32_t property_seed;
    uint32_t random_properties_id;
    uint32_t item_text_id;
    uint32_t durability;
    uint32_t max_durability;
};
#endif

#if VERSION_STRING == WotLK

#define WOWITEM_SPELL_CHARGES_COUNT 5
#define WOWITEM_ENCHANTMENT_COUNT 35

struct WoWItem : WoWObject
{
    union
    {
        struct
        {
            uint32_t low;
            uint32_t high;
        } owner_guid_parts;

        uint64_t owner_guid;
    };
    uint64_t container_guid;
    uint64_t creator_guid;
    uint64_t gift_creator_guid;
    uint32_t stack_count;
    uint32_t duration;
    int32_t spell_charges[WOWITEM_SPELL_CHARGES_COUNT];
    uint32_t flags;
    uint32_t enchantment[WOWITEM_ENCHANTMENT_COUNT];
    uint32_t property_seed;
    uint32_t random_properties_id;
    uint32_t item_text_id;
    uint32_t durability;
    uint32_t max_durability;
};
#endif

#if VERSION_STRING == Cata

#define WOWITEM_SPELL_CHARGES_COUNT 5
#define WOWITEM_ENCHANTMENT_COUNT 44

struct WoWItem : WoWObject
{
    union
    {
        struct
        {
            uint32_t low;
            uint32_t high;
        } owner_guid_parts;

        uint64_t owner_guid;
    };
    uint64_t container_guid;
    uint64_t creator_guid;
    uint64_t gift_creator_guid;
    uint32_t stack_count;
    uint32_t duration;
    int32_t spell_charges[WOWITEM_SPELL_CHARGES_COUNT];
    uint32_t flags;
    uint32_t enchantment[WOWITEM_ENCHANTMENT_COUNT];
    uint32_t property_seed;
    uint32_t random_properties_id;
    uint32_t durability;
    uint32_t max_durability;
    uint32_t create_played_time;
};
#endif

#pragma pack(pop)