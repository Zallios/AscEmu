# Copyright (c) 2014-2018 AscEmu Team <http://www.ascemu.org>

set(PATH_PREFIX GameClassic/Storage)

set(SRC_GAMECLASSIC_STORAGE_FILES
    ${PATH_PREFIX}/DBCStores.cpp
    ${PATH_PREFIX}/DBCStores.h
    ${PATH_PREFIX}/DBCStructures.h
)

source_group(GameClassic\\Storage FILES ${SRC_GAMECLASSIC_STORAGE_FILES})
unset(PATH_PREFIX)
