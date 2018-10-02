/*
Copyright (c) 2014-2018 AscEmu Team <http://www.ascemu.org>
This file is released under the MIT license. See README-MIT for more information.
*/

#pragma once

#include <cstdint>

#include "ManagedPacket.h"
#include "WorldPacket.h"

namespace AscEmu { namespace Packets
{
    class CmsgGmTicketCreate : public ManagedPacket
    {
    public:
        uint32_t map;
        LocationVector location;
        std::string message;
        std::string message2;
        uint32_t responseNeeded;
        bool moreHelpNeeded;
        uint32_t ticketCount;
        std::list<uint32_t> timesList;
        uint32_t decompressedSize;
        std::string chatLog;

        CmsgGmTicketCreate() : CmsgGmTicketCreate(0, { 0.0f, 0.0f, 0.0f }, "", "")
        {
        }

        CmsgGmTicketCreate(uint32_t map, LocationVector location, std::string message, std::string message2) :
            ManagedPacket(CMSG_GMTICKET_CREATE, 4 + 4 * 3 + 2),
            map(map),
            location(location),
            message(message),
            message2(message2)
        {
        }

    protected:
        bool internalSerialise(WorldPacket& packet) override
        {
            return false;
        }

        bool internalDeserialise(WorldPacket& packet) override
        {
#if VERSION_STRING != Cata
            packet >> map >> location.x >> location.y >> location.z >> message >> message2;
#else
            packet >> map >> location.x >> location.y >> location.z >> message >> responseNeeded >> moreHelpNeeded >> ticketCount;

            for (uint32_t i = 0; i < ticketCount; ++i)
            {
                uint32_t time;
                packet >> time;
                timesList.push_back(time);
            }

            packet >> decompressedSize;

            if (ticketCount && decompressedSize && decompressedSize < 0xFFFF)
            {
                uint32 pos = static_cast<uint32_t>(packet.rpos());
                ByteBuffer dest;
                dest.resize(decompressedSize);

                uLongf realSize = decompressedSize;
                if (uncompress(dest.contents(), &realSize, packet.contents() + pos, static_cast<uLong>(packet.size() - pos)) == Z_OK)
                {
                    dest >> chatLog;
                }
                else
                {
                    LOG_ERROR("CMSG_GMTICKET_CREATE failed to uncompress packet.");
                    packet.rfinish();
                    return false;
                }

                packet.rfinish();
            }
#endif

            return true;
        }
    };
}}
