/* Copyright (c) Cheese and Bacon Games, LLC. See docs/LICENSE.md for details. */

#ifndef base_types_h
#define base_types_h

#include <coords.h>
#include <collision.h>
#include <quadtree.h>

#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using String = std::string;
using int64 = std::int64_t;
using uint64 = std::uint64_t;
using int32 = std::int32_t;
using uint32 = std::uint32_t;
using int16 = std::int16_t;
using uint16 = std::uint16_t;
using int8 = std::int8_t;
using uint8 = std::uint8_t;
template<class T> using List = std::vector<T>;
template<class T, class U> using UnorderedMap = std::unordered_map<T, U>;
using Pixels = double;
using Tiles = int32;
using PixelCoords = Coords<Pixels>;
using TileCoords = Coords<Tiles>;
using PixelBox = Collision_Rect<Pixels>;
using Health = int16;
using Index = uint32;
using Quad = Quadtree<Pixels, Index>;
using Indexes = std::unordered_set<Index>;
using Count = uint16;
using Items = uint16;
using Chance = uint16;

#endif
